/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_bigx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-f <fgomes-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:39:45 by fgomes-f          #+#    #+#             */
/*   Updated: 2023/09/21 12:33:09 by fgomes-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	write_bighexa(unsigned int number)
{
	if (number >= 16)
	{
		write_bighexa(number / 16);
		write_bighexa(number % 16);
	}
	else
	{
		if (number <= 9)
		{
			ft_putchar_fd(number + '0', 1);
		}
		else
		{
			ft_putchar_fd(number - 10 + 'A', 1);
		}
	}
}

int	function_bigx(unsigned int number)
{
	unsigned int	copy;
	int				return_value;

	return_value = 1;
	copy = number;
	while (copy >= 16)
	{
		copy = copy / 16;
		return_value++;
	}
	write_bighexa(number);
	return (return_value);
}
