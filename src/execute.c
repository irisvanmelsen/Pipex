/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:35:53 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/05/12 16:23:54 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

// dup2(files[READ], STDIN_FILENO) means that STDIN_FILENO is adjusted so 
// that it now refers to the same open file description as files[READ]
// if the file descriptor STDIN_FILENO was previously open, it is
// automatically closed before being reused
// dup2(files[WRITE], STDOUT_FILEO) means that you write in files[WRITE]
// instead of the standard output

void	child_process(t_pipex *pipex, int files[2], char **argv)
{
	files[READ] = open(argv[1], O_RDONLY);
	if (!files[READ])
		return (print_error(strerror(errno)));
	dup2(files[READ], STDIN_FILENO);
	dup2(files[WRITE], STDOUT_FILENO);
	close(files[READ]);
	while (pipex->cmd->argv)
}


void execute(t_pipex *pipex)
{
	if (pipe(files) == -1)
		return (print_error(get_error_name(ERROR_PIPE)));
	pipex->pid = fork();
	if (pipex->pid == -1)
		return (print_error(get_error_name(ERROR_FORK)));
	if (pipex->pid == 0)
	{
		child_process()
	}
	else
	{
		close()
	}
}