/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:35:53 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/05/16 18:10:10 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

// dup2(files[READ], STDIN_FILENO) means that STDIN_FILENO is adjusted so 
// that it now refers to the same open file description as files[READ]
// if the file descriptor STDIN_FILENO was previously open, it is
// automatically closed before being reused
// dup2(files[WRITE], STDOUT_FILEO) means that you write in files[WRITE]
// instead of the standard output

void	child_first_process(t_pipex *pipex, int files[2], char **argv, int pipe[2])
{
	files[READ] = open(argv[1], O_RDONLY);
	if (!files[READ])
		return (print_error(strerror(errno)));
	files[WRITE] = open(argv[pipex->argc - 1], O_WRONLY | O_CREAT | O_TRUNC);
	if (!files[WRITE])
		return (print_error(strerror(errno)));
	dup_fd(files[READ]);
	close(pipe[READ]);
	dup_fd(files[WRITE]);
	cmds_in_path(pipex->split_path, pipex->cmds->argv[0], pipex);
}

int	cmd_not_found()
{
	// EXIT 127
}

char	*cmds_in_path(char **path, char **split_argv, t_pipex *pipex)
{
	int		i;
	char	*cmd;

	i = -1;
	cmd = ft_strdup(split_argv[0]);
	if (path)
	{
		while (access(cmd, F_OK | X_OK) == -1 && path[i])
		{
			free(cmd);
			i++;
			cmd = ft_strjoin(pipex->split_path[i], split_argv[0]);
		}
		if (path[i] == NULL)
			cmd_not_found(); //EXIT WITH 127 (errno)
	}
	if (execve(cmd, split_argv, pipex->envp) == -1)
		perror("error");
	exit(EXIT_FAILURE);
}

void	execute(t_pipex *pipex, int files[2], char **argv)
{
	pipex->pid = 1;
	if (pipe(files) == -1)
		return (print_error(get_error_name(ERROR_PIPE)));
	if (pipex->pid == -1)
		return (print_error(get_error_name(ERROR_FORK)));
	while (pipex->pid != 0)
	{
		// while loop instead of if or waitpid with 0
		// wait until there are no child processes (wait fails)
		// tellen hoeveel child processes je hebt - 1
		// while (pid != 0 zet 'em op 1)
		// process counter: hoe vaak je looped oftewel children spawned
		pipex->pid = fork();
		// if child process count = 0 etc
		child_first_process(pipex, files, argv, pipe);s
		// if child process count = argc - 1
		child_final_process();
	}
	else
	{
		close()
	}
}

