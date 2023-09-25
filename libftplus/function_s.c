/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-f <fgomes-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:38:52 by fgomes-f          #+#    #+#             */
/*   Updated: 2023/09/21 12:34:23 by fgomes-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	function_s(char *str)
{
	int	i;
	int	return_value;

	return_value = 0;
	i = 0;
	if (str == NULL)
	{
		write (1, "(null)", 6);
		return (6);
	}
	else
	{
		while (str[i] != '\0')
		{
			write (1, &str[i], 1);
			return_value++;
			i++;
		}
		return (return_value);
	}
}
