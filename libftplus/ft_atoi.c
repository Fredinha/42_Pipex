/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:33:15 by fgomes-f          #+#    #+#             */
/*   Updated: 2023/05/08 12:36:32 by fgomes-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_atoi(const char *nptr)
{
	int	i;
	int	atoi;
	int	signal;

	i = 0;
	atoi = 0;
	signal = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			signal = -1;
		i++;
	}
	if (!(nptr[i] >= '0' && nptr[i] <= '9'))
		return (0);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		atoi = atoi * 10;
		atoi = atoi + nptr[i] - 48;
		i++;
	}
	return (atoi * signal);
}

/*
int	main(void)
{
	char test[15] = "   -1234";
	printf("%i\n", ft_atoi(test));
//	printf("%i\n", atoi(test));
}*/
