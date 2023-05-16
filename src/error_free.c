/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:31:52 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/05/16 15:45:02 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*get_error_name(t_error er)
{
	static char	*str[] = {"Allocation Failure",
		"Invalid Type of Argument, Fork Error, Pipe Error, Duplication Error"};

	return (str[er]);
}

int	print_error(char *str)
{
	write (STDERR_FILENO, str, ft_strlen(str));
	write (STDERR_FILENO, "\n", 1);
	return (EXIT_FAILURE);
}