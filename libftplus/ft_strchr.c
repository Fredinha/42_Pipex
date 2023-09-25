/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-f <fgomes-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 14:29:35 by fgomes-f          #+#    #+#             */
/*   Updated: 2023/05/08 17:50:57 by fgomes-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	char			*s_copy;
	unsigned char	c_copy;

	i = 0;
	c_copy = (unsigned char) c;
	s_copy = (char *) s;
	while (i <= ft_strlen(s))
	{
		if ((unsigned char) s[i] == c_copy)
			return (s_copy + i);
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
	printf("%s\n", ft_strchr("fred linda e fofa", 32));
	printf("%s\n", strchr("fred linda e fofa", 32));
}*/
