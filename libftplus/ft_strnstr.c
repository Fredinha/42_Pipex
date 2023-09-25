/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:15:55 by fgomes-f          #+#    #+#             */
/*   Updated: 2023/04/24 16:00:18 by fgomes-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdio.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	j;
	size_t	i;

	i = 0;
	if (little[0] == '\0')
		return ((char *) big);
	while (i < len && big[i] != '\0')
	{
		j = 0;
		if (little[j] == big[i])
		{
			while (i + j < len && big[i + j] == little[j])
			{
				j++;
				if (little[j] == '\0')
					return ((char *) big + i);
			}
		}
		i++;
	}
	return (NULL);
}
