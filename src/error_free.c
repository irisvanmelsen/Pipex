/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:31:52 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/05/22 19:18:13 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*get_error_name(t_error er)
{
	static char	*str[] = {[ERROR_ALLOCATION] = "Allocation Failure", \
		[ERROR_ARGUMENTS] = "Invalid Type of Argument", \
		[ERROR_FORK] = "Fork Error", \
		[ERROR_PIPE] = "Pipe Error", \
		[ERROR_DUP2] = "Duplication Error", \
		[ERROR_PATH] = "Command not Found"};

	return (str[er]);
}

int	print_error(char *str)
{
	write (STDERR_FILENO, str, ft_strlen(str));
	write (STDERR_FILENO, "\n", 2);
	return (EXIT_FAILURE);
}