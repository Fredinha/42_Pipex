/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:23:38 by fgomes-f          #+#    #+#             */
/*   Updated: 2023/05/08 19:09:06 by fgomes-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	char	*help;
	size_t	i;

	i = 0;
	help = s;
	if (n == 0)
		return ;
	else
	{
		while (i < n)
		{
			help[i] = '\0';
			i++;
		}
	}
}

/*int	main(void)
{
	char str[10] = "frederica";

        printf("original string: %s\n", str);
        ft_bzero(str, 2);
	//bzero(str, 2);
        printf("new string: %s\n", str);

        return (0);
}*/
