/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:31:49 by fgomes-f          #+#    #+#             */
/*   Updated: 2023/04/20 13:24:50 by fgomes-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1024);
	else
		return (0);
}

/*int	main(void)
{
	printf("%i", ft_isalpha('a'));
	printf("%i", ft_isalpha('z'));
	printf("%i", ft_isalpha('e'));
	printf("%i", ft_isalpha('A'));
	printf("%i", ft_isalpha('Z'));
	printf("%i", ft_isalpha('W'));
	printf("%i", ft_isalpha('1'));
	printf("%i", ft_isalpha('0'));
	printf("%i", ft_isalpha('*'));
	printf("%i", ft_isalpha(' '));
}*/
