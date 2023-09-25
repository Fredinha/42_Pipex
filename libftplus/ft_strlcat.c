/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-f <fgomes-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:34:25 by fgomes-f          #+#    #+#             */
/*   Updated: 2023/04/23 15:51:11 by fgomes-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;
	size_t	dst_len;
	size_t	sum_len;

	i = 0;
	sum_len = 0;
	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (dst == src)
		return (0);
	if (size > dst_len)
		sum_len = src_len + dst_len;
	else
		return (src_len + size);
	if (size == 0)
		return (sum_len);
	while (src[i] != '\0' && dst_len < (size - 1))
	{
		dst[dst_len] = src[i];
		dst_len++;
		i++;
	}
	dst[dst_len] = '\0';
	return (sum_len);
}

/*int	main(void)
{
	char dest [14] = "a";
	printf("%zu", ft_strlcat(dest, "lorem ipsum dolor sit amet", 15));
	printf("%s", dest);
}*/
