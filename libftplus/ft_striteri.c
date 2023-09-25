/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-f <fgomes-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:32:33 by fgomes-f          #+#    #+#             */
/*   Updated: 2023/05/05 12:41:39 by fgomes-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/*void	f(unsigned int i, char	*s)
{
	(void) i;
	if (*s >= 'a' && *s <= 'z')
		*s = *s - 32;
}

int	main(void)
{
	char s1[12] = "abcdefeghij";
	ft_striteri(s1, &f);
	printf("%s", s1);
}*/
