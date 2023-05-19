/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 14:38:58 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/05/19 20:29:45 by ivan-mel         ###   ########.fr       */
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
			return (envp[index] + 5);
		index++;
	}
	return (NULL);
}

int	split_args(t_pipex *pipex)
{
	int	i;

	i = 2;
	pipex->cmds = ft_calloc(sizeof (t_cmd), pipex->argc - 2);
	if (!pipex->cmds)
		return (print_error(get_error_name(ERROR_ALLOCATION)));
	while (i != pipex->argc - 1)
	{
		pipex->cmds[i - 2].args = ft_split(pipex->argv[i], ' ');
		i++;
	}
	return (EXIT_SUCCESS);
}

char	**split_path(char *path)
{
	int		index;
	char	**path2;

	index = 0;
	if (!path)
		return (NULL);
	path2 = ft_split(path, ':');
	if (!path2)
		return (NULL);
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

int	check_args(t_pipex *pipex)
{
	int		index;
	char	*path;

	index = 0;
	if (pipex->argc != 5)
		return (print_error(get_error_name(ERROR_ARGUMENTS)));
	path = find_path(pipex->envp);
	pipex->split_path = split_path(path);
	if (!pipex->split_path)
		return (print_error(get_error_name(ERROR_ALLOCATION)));
	if (split_args(pipex) == 1)
		return (print_error("Can't Split Arguments"));
	return (EXIT_SUCCESS);
}