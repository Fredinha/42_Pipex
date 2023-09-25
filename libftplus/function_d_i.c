/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_d_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-f <fgomes-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:11:34 by fgomes-f          #+#    #+#             */
/*   Updated: 2023/09/21 12:35:29 by fgomes-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	function_d_i(int number)
{
	char	*written_number;
	int		i;
	int		return_value;

	i = 0;
	return_value = 0;
	written_number = ft_itoa(number);
	if (!written_number || written_number[i] == '\0')
	{
		write (1, "(null)", 6);
		return (6);
	}
	else
	{
		while (written_number[i] != '\0')
		{
			ft_putchar_fd(written_number[i], 1);
			return_value++;
			i++;
		}
	}
	free(written_number);
	return (return_value);
}
