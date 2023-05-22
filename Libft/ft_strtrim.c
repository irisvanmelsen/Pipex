/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:05:56 by ivan-mel          #+#    #+#             */
/*   Updated: 2023/05/22 18:19:53 by ivan-mel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(s1);
	while (ft_strchr(set, s1[i]) != NULL && i < ft_strlen(s1))
		i++;
	while (ft_strchr(set, s1[j]) != NULL && i < j)
			j--;
	result = ft_substr(s1, i, (j - i + 1));
	return (result);
}
/*
int	main(void)
{
	char const str [] = "  \t \t \n   \n\n\n\t";
	char const str1 [] = " \n\t";
	printf("%s", ft_strtrim(str, str1));
	return (0);
}*/
