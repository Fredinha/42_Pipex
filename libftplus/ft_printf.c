/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-f <fgomes-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:54:13 by fgomes-f          #+#    #+#             */
/*   Updated: 2023/09/11 16:58:47 by fgomes-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	what_is_this(va_list args, char c)
{
	if (c == 'c')
		return (function_c(va_arg(args, int)));
	if (c == 's')
		return (function_s(va_arg(args, char *)));
	if (c == 'd' || c == 'i')
		return (function_d_i(va_arg(args, int)));
	if (c == 'u')
		return (function_u(va_arg(args, unsigned int)));
	if (c == 'p')
		return (function_p(va_arg(args, unsigned long long)));
	if (c == 'x')
		return (function_x(va_arg(args, unsigned int)));
	if (c == 'X')
		return (function_bigx(va_arg(args, unsigned int)));
	if (c == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	return (0);
}

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		i;
	int		return_value;

	i = 0;
	return_value = 0;
	va_start(args, string);
	while (string[i])
	{
		if (string[i] == '%')
		{
			i++;
			return_value = return_value + what_is_this(args, string[i]);
		}
		else
		{
			ft_putchar_fd((char) string[i], 1);
			return_value++;
		}
		i++;
	}
	va_end(args);
	return (return_value);
}

/*int		main(void)
{
	char	a;
	char	*str;
	char	*str2;
	char	percent;
	int		i;
	unsigned int	b;
	unsigned int	hex;

	a = 'a';
	str = "ugdygd";
	str2 = "10";
	i = -42174612;
	b = -42174612;
	hex = -10;
	percent = '%';

	// %c
	write(1, "\nft_putchar:\n", 13);
	printf("%d\n", printf("%c\n", a));
	ft_printf("%d\n", ft_printf("%c\n", a));
	
 	// %s
	write(1, "\nft_putstr:\n", 12);
	printf("%d char\n", printf("%s\n", str));
	ft_printf("%d char\n", ft_printf("%s\n", str));
	
	// %p
	write(1, "\nft_putptr\n", 11);
	printf("%d char\n", printf("%p\n", str2));
	ft_printf("%d char\n", ft_printf("%p\n", str2));
		
 	// %d
	write(1, "\nft_nbr d:\n", 11);
	printf("%d char\n", printf("%d\n", i));
	ft_printf("%d char\n", ft_printf("%d\n", i));

	// %i
	write(1, "\nft_nbr i:\n", 11);
	printf("%d char\n", printf("%i\n", i));
	ft_printf("%d char\n", ft_printf("%i\n", i));
   	
	int n = -2147483648;
  	ft_printf("\nNum is: %d\n", n);
	printf("Num is: %d\n", n);	
	ft_printf("\nNum is: %i\n", n);
	printf("Num is: %i\n", n);	

	// %u
	write(1, "\nft_unsigned\n", 13);
	printf("%d\n", printf("%u\n", b));
	printf("%d\n", ft_printf("%u\n", b));

	// %x
	write(1, "\nft_x:\n", 7);
	printf("%d\n", printf("%x\n", hex));
	ft_printf("%d\n", ft_printf("%x\n", hex));

	// %X
	write(1, "\nft_X:\n", 7);
	printf("%d\n", printf("%X\n", hex));
	ft_printf("%d\n", ft_printf("%X\n", hex));

	// %%
	write(1, "\nft_percent:\n", 13);
	printf("%d\n", printf("%%\n"));
	ft_printf("%d\n", ft_printf("%%\n", percent));
	printf("\n");
}*/
