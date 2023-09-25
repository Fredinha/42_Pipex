/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-f <fgomes-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:44:45 by fgomes-f          #+#    #+#             */
/*   Updated: 2023/05/19 13:16:39 by fgomes-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	write_long_hexa(unsigned long long number)
{
	if (number >= 16)
	{
		write_long_hexa(number / 16);
		write_long_hexa(number % 16);
	}
	else
	{
		if (number <= 9)
		{
			ft_putchar_fd(number + '0', 1);
		}
		else
		{
			ft_putchar_fd(number - 10 + 'a', 1);
		}
	}
}

int	function_p(unsigned long long number)
{
	unsigned long long	copy;
	int					return_value;

	return_value = 3;
	copy = number;
	if (number == 0)
	{
		write (1, "(nil)", 5);
		return (5);
	}
	write (1, "0x", 2);
	while (copy >= 16)
	{
		copy = copy / 16;
		return_value++;
	}
	write_long_hexa(number);
	return (return_value);
}
