/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:09:30 by fgomes-f          #+#    #+#             */
/*   Updated: 2023/04/20 13:28:14 by fgomes-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}

/*int	main(void)
{
	printf("%i\n", ft_toupper('a'));
	printf("%i\n", ft_toupper('A'));
        printf("%i\n", ft_toupper('9'));
        printf("%i\n", toupper('a'));
        printf("%i\n", toupper('A'));
        printf("%i", toupper('9'));
}*/
