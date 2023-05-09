/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 14:38:58 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/05/09 18:39:32 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*find_path(char **envp)
{
	int		index;

	index = 0;
	while (envp[index])
	{
		if (ft_strncmp(envp[index], "PATH=", 5) == 0)
			break ;
		index++;
	}
	return (envp[index] + 5);
}

int	split_args(char **argv, t_pipex *pipex)
{
	pipex->cmd1 = ft_split(argv[2], ' ');
	if (!pipex->cmd1)
		return (EXIT_FAILURE);
	pipex->cmd2 = ft_split(argv[3], ' ');
	if (!pipex->cmd2)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

char	**split_path(char *path)
{
	int		index;
	char	**path2;

	index = 0;
	path2 = ft_split(path, ':');
	if (!path)
	{
		write(1, "Can't Split Path\n", 17);
		return (NULL);
	}
	path2 = put_slash(path2);
	return (path2);
}

char	**put_slash(char **path)
{
	char	*temp;
	int		index;

	index = 0;
	while (path[index])
	{
		temp = ft_strjoin(path[index], "/");
		if (!temp)
		{
			free_2d(path);
			return (NULL);
		}
		free(path[index]);
		path[index] = temp;
		index++;
	}
	return (path);
}

int	check_args(char **argv, int argc, char **envp, t_pipex *pipex)
{
	valid_args(argc, argv);
	pipex->path = find_path(envp);
	if (!pipex->path)
		return (EXIT_FAILURE);
	if (split_args(argv, pipex) == 1)
	{
		write(1, "Can't Split Arguments\n", 13);
		return (EXIT_FAILURE);
	}
	pipex->split_path = split_path(pipex->path);
	return (EXIT_SUCCESS);
}