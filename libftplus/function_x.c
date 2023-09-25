/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-f <fgomes-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:56:11 by fgomes-f          #+#    #+#             */
/*   Updated: 2023/05/19 13:06:25 by fgomes-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	write_hexa(unsigned int number)
{
	if (number >= 16)
	{
		write_hexa(number / 16);
		write_hexa(number % 16);
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

int	function_x(unsigned int number)
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
	write_hexa(number);
	return (return_value);
}

/*int	main(void)
{
	printf("%i", function_x(134));
}*/
