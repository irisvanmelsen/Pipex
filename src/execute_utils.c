/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:44:53 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/05/16 16:42:38 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	check_stdin(int file)
{
	if (dup2(file, STDIN_FILENO) == -1)
	{
		close(file);
		return (print_error(get_error_name(ERROR_DUP2)));
	}
	close (file);
	return (0);
}

int	check_stdout(int file)
{
	if (dup2(file, STDOUT_FILENO) == -1)
	{
		close(file);
		return (print_error(get_error_name(ERROR_DUP2)));
	}
	close (file);
	return (0);
}
