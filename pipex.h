/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:30:50 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/05/16 18:09:41 by ivan-mel         ###   ########.fr       */
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
}	t_error;

typedef struct s_cmd {
	char	**argv;
	int		cmd_nb;
}	t_cmd;

typedef struct s_pipex {
	char	**split_path;
	int		pid;
	int		argc;
	char	**envp;
	t_cmd	*cmds;	
}	t_pipex;

// PARSING:

char	*find_path(char **envp);
int		split_args(char **argv, t_pipex *pipex);
char	**split_path(char *path);
char	**put_slash(char **path);
int		check_args(char **argv, t_pipex *pipex);

// PARSING_UTILS

int		cmd_amount(char **cmds);

// EXECUTE

void	child_first_processs(t_pipex *pipex, int files[2], char **argv, int pipe[2]);
char	*cmds_in_path(char **path, char **split_argv, t_pipex *pipex);
void	execute(t_pipex *pipex, int files[2], char **argv);

// EXECUTE_UTILS

int		check_stdin(int file);
int		check_stdout(int file);

// FREE:

void	free_2d(char **str);

// ERROR:

char	*get_error_name(t_error er);
int		print_error(char *str);
int		dup_fd(int fd);

#endif