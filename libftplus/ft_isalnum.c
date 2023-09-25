/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:31:13 by fgomes-f          #+#    #+#             */
/*   Updated: 2023/04/20 13:24:22 by fgomes-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z'))
		return (8);
	else
		return (0);
}

/*int	main(void)
{
	printf("%i", ft_isalnum('1'));
	printf("%i", ft_isalnum('a'));
	printf("%i", ft_isalnum('J'));
	printf("%i", ft_isalnum(' '));
	printf("%i", ft_isalnum('+'));
}*/
