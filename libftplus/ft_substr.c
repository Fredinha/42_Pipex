/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 11:52:51 by fgomes-f          #+#    #+#             */
/*   Updated: 2023/05/08 19:08:07 by fgomes-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		substring = malloc(1);
		substring[0] = '\0';
		return (substring);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	substring = malloc(sizeof(char) * len + 1);
	if (!substring)
		return (NULL);
	while (i < len)
	{
		substring[i] = s[start];
		i++;
		start++;
	}
	substring[i] = '\0';
	return (substring);
}

/*int	main(void)
{
	printf("%s", ft_substr("a fred e linda", 2, 4));
}*/
