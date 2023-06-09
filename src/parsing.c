/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 14:38:58 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/05/24 14:19:42 by ivan-mel         ###   ########.fr       */
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
	exit(print_error(get_error_name(ERROR_ENV_PATH)));
}

int	split_args(t_pipex *pipex)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	pipex->cmds = ft_calloc(sizeof (t_cmd), pipex->argc - 1);
	if (!pipex->cmds)
		return (print_error(get_error_name(ERROR_ALLOCATION)));
	while (i != pipex->argc)
	{
		pipex->cmds[j].args = ft_split(pipex->argv[i], ' ');
		i++;
		j++;
	}
	return (EXIT_SUCCESS);
}

char	**split_path(char *path)
{
	char	**path2;

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
	char	*path;

	path = find_path(pipex->envp);
	pipex->split_path = split_path(path);
	if (!pipex->split_path)
		return (print_error(get_error_name(ERROR_ALLOCATION)));
	if (split_args(pipex) == 1)
		return (print_error("Can't Split Arguments"));
	return (EXIT_SUCCESS);
}