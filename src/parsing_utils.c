/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:00:06 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/05/11 13:58:24 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	valid_args(int argc)
{
	int	index;

	index = 0;
	if (argc != 5)
	{
		write(1, "Invalid Amount of Arguments\n", 28);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}