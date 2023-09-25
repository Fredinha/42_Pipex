/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 18:31:11 by fgomes-f          #+#    #+#             */
/*   Updated: 2023/05/08 15:37:27 by fgomes-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*dst_c;
	char	*src_c;
	size_t	i;

	if (!dest && !src)
		return (NULL);
	dst_c = (char *) dest;
	src_c = (char *) src;
	if (src_c < dst_c)
	{
		i = n;
		while (i-- > 0)
			dst_c[i] = src_c[i];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			dst_c[i] = src_c[i];
			i++;
		}
	}
	return (dest);
}

/*int   main(void)
{
        const void *src = "frederica";
        void *dest = malloc(12);

        printf("original string: %s\n", (char *) src);
        //memmove(dest, src, 2);
        ft_memmove(dest, src, 2);
        printf("new string: %s\n", (char *) dest);

        free (dest);
        return (0);
}
*/
