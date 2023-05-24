/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:06:43 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/05/24 14:09:58 by ivan-mel         ###   ########.fr       */
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
	t_pipex	pipex;
	int		pipes[2];

	if (argc != 5)
		return (print_error(get_error_name(ERROR_ARGUMENTS)));
	pipex.argc = argc - 1;
	pipex.envp = envp;
	pipex.argv = &argv[1];
	pipex.count = argc - 3;
	if (check_char(pipex.argv) == 1)
		print_error(get_error_name(ERROR_ARGUMENTS));
	check_args(&pipex);
	execute(&pipex, pipes);
	system("leaks pipex");
}
