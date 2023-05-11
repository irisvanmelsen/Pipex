/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:30:50 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/05/11 18:56:07 by ivan-mel         ###   ########.fr       */
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
# include <sys/errno.h>
# include <string.h>

typedef enum e_files
{
	READ,
	WRITE,
}	t_files;

typedef enum e_error
{
	ERROR_ALLOCATION,
	ERROR_ARGUMENTS,
}	t_error;

typedef struct s_cmd
{
	char	**argv;
}	t_cmd;

typedef struct s_pipex
{
	char	*path;
	char	**split_path;

	t_cmd	*cmds;
}	t_pipex;

// PARSING:

char	*find_path(char **envp);
int		split_args(char **argv, int argc, t_pipex *pipex);
char	**split_path(char *path);
char	**put_slash(char **path);
int		check_args(char **argv, int argc, char **envp, t_pipex *pipex);

// PARSING UTILS:

int		valid_args(int argc);

// FREE:

void	free_2d(char **str);

// ERROR:

char	*get_error_name(t_error er);
int		print_error(char *str);

#endif