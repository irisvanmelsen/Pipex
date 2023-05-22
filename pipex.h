/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:30:50 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/05/22 19:10:10 by ivan-mel         ###   ########.fr       */
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
#include <sys/wait.h>
# include <string.h>

typedef enum e_files {
	READ,
	WRITE,
}	t_files;

typedef enum e_error {
	ERROR_ALLOCATION,
	ERROR_ARGUMENTS,
	ERROR_FORK,
	ERROR_PIPE,
	ERROR_DUP2,
	ERROR_PATH,
}	t_error;

typedef struct s_cmd {
	char	**args;
}	t_cmd;

typedef struct s_pipex {
	char	**split_path;
	int		pid;
	int		argc;
	char	**envp;
	char	**argv;
	int		count;
	t_cmd	*cmds;	
}	t_pipex;

// PARSING:

char	*find_path(char **envp);
int		split_args(t_pipex *pipex);
char	**split_path(char *path);
char	**put_slash(char **path);
int		check_args(t_pipex *pipex);

// EXECUTE

void	child_first(t_pipex *pipex, int pipes[2]);
void	child_last(t_pipex *pipex, int pipes[2]);
void	cmds_in_path(char **path, char **split_argv, t_pipex *pipex);
void	children_spawn(t_pipex *pipex, int pipes[2]);
void	execute(t_pipex *pipex, int pipes[2]);

// EXECUTE_UTILS

int		check_stdin(int file);
int		check_stdout(int file);
char	*find_access(char **path, char **split_argv, t_pipex *pipex, char *cmd);

// FREE:

void	free_2d(char **str);

// ERROR:

char	*get_error_name(t_error er);
int		print_error(char *str);

#endif