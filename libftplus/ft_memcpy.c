/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 15:51:09 by fgomes-f          #+#    #+#             */
/*   Updated: 2023/05/05 15:56:29 by fgomes-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*dest_copy;
	char	*src_copy;

	if (dest == NULL && src == NULL && n > 0)
		return (NULL);
	dest_copy = (char *) dest;
	src_copy = (char *) src;
	i = 0;
	while (i < n)
	{
		dest_copy[i] = src_copy[i];
		i++;
	}
	return (dest);
}

/*int	main(void)
{
        const void *src = "frederica";
	void *dest = malloc(12);

        printf("original string: %s\n", (char *) src);
        //memcpy(dest, src, 2);
        ft_memcpy(dest, src, 2);
        printf("new string: %s\n", (char *) dest);

	free (dest);
        return (0);
}*/
