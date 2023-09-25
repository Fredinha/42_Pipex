/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-f <fgomes-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:25:12 by fgomes-f          #+#    #+#             */
/*   Updated: 2023/05/19 13:09:40 by fgomes-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_create_malloc(unsigned int n, unsigned int n_of_chars)
{
	char	*string;

	string = malloc(sizeof(char) * n_of_chars + 1);
	if (!string)
		return (NULL);
	string[n_of_chars] = '\0';
	while (n_of_chars != 0)
	{
		n_of_chars--;
		string[n_of_chars] = (n % 10) + 48;
		n = n / 10;
	}
	return (string);
}

char	*unsigned_itoa(unsigned int n)
{
	unsigned int	n_of_chars;
	unsigned int	n_copy;

	n_of_chars = 1;
	n_copy = n;
	while (n_copy >= 10)
	{
		n_copy = n_copy / 10;
		n_of_chars++;
	}
	return (ft_create_malloc(n, n_of_chars));
}

int	function_u(unsigned int number)
{
	char	*written_number;
	int		i;
	int		return_value;

	i = 0;
	return_value = 0;
	written_number = unsigned_itoa(number);
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
