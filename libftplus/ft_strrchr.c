/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-f <fgomes-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 12:35:17 by fgomes-f          #+#    #+#             */
/*   Updated: 2023/05/08 19:09:15 by fgomes-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	char			*s_copy;
	unsigned char	c_copy;

	c_copy = (unsigned char) c;
	i = ft_strlen(s);
	s_copy = (char *) s;
	if (!s)
		return (NULL);
	while (i >= 0)
	{
		if (s[i] == c_copy)
			return (s_copy + i);
		i--;
	}
	return (NULL);
}

/*int	main(void)
{
	printf("%s\n", ft_strrchr("fred linda e fofa", 32));
	printf("%s\n", strrchr("fred linda e fofa", 32));
}*/
