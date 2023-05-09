/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:30:50 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/05/09 18:39:46 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>

typedef enum s_
{
	HALLO,
	READ,
	WRITE,
}	t_;

typedef struct s_pipex
{
	char	*path;
	char	**split_path;
	char	*args;
	char	**cmd1;
	char	**cmd2;
}	t_pipex;

// PARSING:

char	*find_path(char **envp);
int		split_args(char **argv, t_pipex *pipex);
char	**split_path(char *path);
char	**put_slash(char **path);
int		check_args(char **argv, int argc, char **envp, t_pipex *pipex);

// PARSING UTILS:

int		valid_args(int argc, char **argv);

// FREE:

void	free_2d(char **str);

#endif