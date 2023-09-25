/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:17:29 by fgomes-f          #+#    #+#             */
/*   Updated: 2023/04/20 15:09:50 by fgomes-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}

/*int	main(void)
{
	printf("%i\n", ft_tolower('a'));
	printf("%i\n", ft_tolower('A'));
	printf("%i\n", ft_tolower('9'));
	printf("%i\n", tolower('a'));
	printf("%i\n", tolower('A'));
	printf("%i", tolower('9'));
}*/
