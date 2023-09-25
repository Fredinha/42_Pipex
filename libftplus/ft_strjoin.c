/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:55:32 by fgomes-f          #+#    #+#             */
/*   Updated: 2023/05/08 18:42:42 by fgomes-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	string = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!string)
		return (NULL);
	while (s1[i] != '\0')
	{
		string[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		string[i] = s2[j];
		j++;
		i++;
	}
	string[i] = '\0';
	return (string);
}

/*int	main(void)
{
	char	*str1;
	char	*str2;

	str1 = "a fred e";
	str2 = " linda";
	printf("%s", ft_strjoin(str1, str2));
}*/
