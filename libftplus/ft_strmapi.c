/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-f <fgomes-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:16:28 by fgomes-f          #+#    #+#             */
/*   Updated: 2023/05/08 18:52:25 by fgomes-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*string;
	unsigned int	i;

	string = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!string)
		return (NULL);
	i = 0;
	while (s[i])
	{
		string[i] = f(i, s[i]);
		i++;
	}
	string[i] = '\0';
	return (string);
}

/*char	f(unsigned int i, char c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 32;
	return(c);
}

int	main(void)
{
	char s1[16] = "a fred e linda";
	printf("%s", ft_strmapi(s1, &f));
}*/
