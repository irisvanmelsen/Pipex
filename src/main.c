/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:06:43 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/05/19 21:35:33 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

//./pipex infile cmd1 cmd2 outfile
// we read from infile, execute cmd1 with infile as input
// send the output to cmd2 which will write to the outfile

//fork: clone the calling process, creating an exact copy
// return -1 for errors, 0 to the new process, and
// the process ID of the new process to the old process

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;
	int		pipes[2];

	pipex = ft_calloc(1, sizeof(t_pipex));
	if (!pipex)
		return (print_error(get_error_name(ERROR_ALLOCATION)));
	pipex->argc = argc;
	pipex->envp = envp;
	pipex->argv = argv;
	pipex->count = argc - 3;
	check_args(pipex);
	execute(pipex, pipes);
}