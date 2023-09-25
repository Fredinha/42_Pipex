/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 18:05:20 by fgomes-f          #+#    #+#             */
/*   Updated: 2023/05/08 15:30:43 by fgomes-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*s1_copy;
	char	*s2_copy;
	size_t	i;

	i = 0;
	s1_copy = (char *) s1;
	s2_copy = (char *) s2;
	while (i < n)
	{
		if (s1_copy[i] != s2_copy[i])
			return ((unsigned char)s1_copy[i] - (unsigned char)s2_copy[i]);
		i++;
	}
	return (0);
}

/*int	main(void)
{
	char	*s1;
	char	*s2;

	s1 = "a fred e linda";
	s2 = "a fred e lindb";
//	printf("%i\n", ft_memcmp(s1, s2, 15));
	printf("%i\n", memcmp(s1, s2, 15));
}*/
