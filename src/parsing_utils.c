/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:00:06 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/05/09 17:58:14 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	valid_args(int argc, char **argv)
{
	int	index;

	index = 0;
	if (argc != 5)
	{
		write(1, "Invalid Amount of Arguments\n", 28);
		return (EXIT_FAILURE);
	}
	if (argv[index][0] == '\0')
	{
		write(1, "Empty Argument\n", 13);
		return (EXIT_FAILURE);
	}
}