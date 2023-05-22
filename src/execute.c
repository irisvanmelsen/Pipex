/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:35:53 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/05/22 19:21:19 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

// dup2(files[READ], STDIN_FILENO) means that STDIN_FILENO is adjusted so 
// that it now refers to the same open file description as files[READ]
// if the file descriptor STDIN_FILENO was previously open, it is
// automatically closed before being reused
// dup2(files[WRITE], STDOUT_FILEO) means that you write in files[WRITE]
// instead of the standard output

void	child_first(t_pipex *pipex, int pipes[2])
{
	int	fd;

	close(pipes[READ]);
	fd = open(pipex->argv[0], O_RDONLY);
	if (fd == -1)
	{
		print_error(strerror(errno));
		return ;
	}
	check_stdin(fd);
	check_stdout(pipes[WRITE]);
	cmds_in_path(pipex->split_path, pipex->cmds[0].args, pipex);
	exit(127);
}

void	child_last(t_pipex *pipex, int pipes[2])
{
	int	fd;

	close(pipes[WRITE]);
	fd = open(pipex->argv[pipex->argc - 1],
			O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		print_error(strerror(errno));
		return ;
	}
	check_stdout(fd);
	check_stdin(pipes[READ]);
	cmds_in_path(pipex->split_path, pipex->cmds[1].args, pipex);
	exit(127);
}

void	cmds_in_path(char **path, char **split_argv, t_pipex *pipex)
{
	char	*cmd;

	cmd = ft_strdup(split_argv[0]);
	if (!cmd)
		return ;
	cmd = find_access(path, split_argv, pipex, cmd);
	if (execve(cmd, split_argv, pipex->envp) == -1)
	{
		free(pipex->split_path);
		perror("error");
	}
	return ;
}

void	children_spawn(t_pipex *pipex, int pipes[2])
{
	int	i;

	i = 0;
	while (i < pipex->count)
	{
		pipex->pid = fork();
		if (pipex->pid == -1)
		{
			print_error(get_error_name(ERROR_FORK));
			exit(1);
		}
		if (pipex->pid == 0)
		{
			if (i == 0)
				child_first(pipex, pipes);
			else if (i == 1)
				child_last(pipex, pipes);
		}
		i++;
	}
}

void	execute(t_pipex *pipex, int pipes[2])
{
	int	status;

	status = 0;
	if (pipe(pipes) == -1)
	{
		print_error(get_error_name(ERROR_PIPE));
		return ;
	}
	children_spawn(pipex, pipes);
	close(pipes[READ]);
	close(pipes[WRITE]);
	waitpid(pipex->pid, &status, 0);
	while (wait(NULL) != -1)
		continue ;
	exit((WEXITSTATUS(status)));
}
