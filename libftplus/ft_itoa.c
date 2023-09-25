/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:40:05 by fgomes-f          #+#    #+#             */
/*   Updated: 2023/05/09 12:51:32 by fgomes-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static char	*ft_create_malloc(int n, int n_of_chars, int signal)
{
	char	*string;

	string = malloc(sizeof(char) * n_of_chars + 1 + signal);
	if (!string)
		return (NULL);
	string[n_of_chars + signal] = '\0';
	while (n_of_chars != 0)
	{
		n_of_chars--;
		string[n_of_chars + signal] = (n % 10) + 48;
		n = n / 10;
	}
	if (signal == 1)
		string[0] = '-';
	return (string);
}

static char	*ft_special_case(int n)
{
	char	*string;

	string = malloc(12);
	string[0] = '-';
	string[1] = '2';
	string[2] = '1';
	string[3] = '4';
	string[4] = '7';
	string[5] = '4';
	string[6] = '8';
	string[7] = '3';
	string[8] = '6';
	string[9] = '4';
	string[10] = '8';
	string[11] = '\0';
	if (!string)
		return (NULL);
	if (n == -2147483648)
		return (string);
	return (NULL);
}

char	*ft_itoa(int n)
{
	int	signal;
	int	n_of_chars;
	int	n_copy;

	n_of_chars = 1;
	signal = 0;
	if (n < 0 && n != (-2147483648))
	{
		n = n * (-1);
		signal = 1;
	}
	if (n == (-2147483648))
		return (ft_special_case(n));
	n_copy = n;
	while (n_copy >= 10)
	{
		n_copy = n_copy / 10;
		n_of_chars++;
	}
	return (ft_create_malloc(n, n_of_chars, signal));
}

/*int	main(void)
{
	printf("%s\n", ft_itoa(23674));
	printf("%s\n", ft_itoa(-2147483648));
}*/
