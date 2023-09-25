/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 15:05:12 by fgomes-f          #+#    #+#             */
/*   Updated: 2023/05/08 18:27:40 by fgomes-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strdup(const char	*s)
{
	char	*dest;
	int		i;

	i = 0;
	dest = (char *) malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!dest)
		return (NULL);
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*int	main(void)
{
	char	*str;
	char	*copy1;
	char	*copy2;

	str = "A fred e linda";
	copy1 = ft_strdup(str);
	copy2 = strdup(str);
	printf("my function: %s\noriginal function: %s\n", copy1, copy2);
}*/
