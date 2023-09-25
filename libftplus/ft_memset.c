/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 15:25:49 by fgomes-f          #+#    #+#             */
/*   Updated: 2023/05/05 14:23:18 by fgomes-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <unistd.h>
#include <stdio.h>

void	*ft_memset(void *s, int c, size_t n)
{
	char	*s_copy;
	size_t	i;

	s_copy = (char *) s;
	i = 0;
	while (i < n)
	{
		s_copy[i] = c;
		i++;
	}
	return (s);
}

/*int	main(void)
{
	char str[10] = "frede";

	printf("original: %s\n", str);
	ft_memset(str, 'F', 2);
	printf("new string: %s\n", str);

	return (0);
}*/
