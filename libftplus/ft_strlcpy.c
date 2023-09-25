/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:21:18 by fgomes-f          #+#    #+#             */
/*   Updated: 2023/04/21 12:52:28 by fgomes-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	x;

	i = 0;
	x = 0;
	if (size == 0)
	{
		while (src[i] != '\0')
			i++;
		return (i);
	}
	if (src[0] == '\0')
		dst[0] = '\0';
	while (src[i] != '\0' && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	while (src[x] != '\0')
		x++;
	return (x);
}

/*int	main(void)
{
	char	dst[100] = "rrrrrr";
	printf("%zu\n", ft_strlcpy(dst, "lorem ipsum dolor sit amet", 0));
	printf("%s", dst);
}*/
