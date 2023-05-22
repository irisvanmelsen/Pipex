/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:44:53 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/05/22 19:13:26 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"


int	check_stdin(int file)
{
	if (dup2(file, STDIN_FILENO) == -1)
	{
		close(file);
		return (print_error(get_error_name(ERROR_DUP2)));
	}
	close(file);
	return (0);
}

int	check_stdout(int file)
{
	if (dup2(file, STDOUT_FILENO) == -1)
	{
		close(file);
		return (print_error(get_error_name(ERROR_DUP2)));
	}
	close(file);
	return (0);
}

char	*find_access(char **path, char **split_argv, t_pipex *pipex, char *cmd)
{
	int	i;

	i = 0;
	if (!path || cmd[0] == '/' || ft_strncmp(cmd, "./", 2) == 0)
		return (cmd);
	while (path[i])
	{
		free(cmd);
		cmd = ft_strjoin(pipex->split_path[i], split_argv[0]);
		if (!cmd)
			return (NULL);
		if (access(cmd, X_OK | F_OK) == 0)
			break ;
		i++;
	}
	return (cmd);
}