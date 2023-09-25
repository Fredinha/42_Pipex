/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-f <fgomes-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 13:21:21 by fgomes-f          #+#    #+#             */
/*   Updated: 2023/09/21 12:35:49 by fgomes-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_is_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static char	*ft_build_string(char *string, char const *s1, size_t i, size_t j)
{
	size_t	x;

	x = 0;
	if (!string)
		return (NULL);
	while (j > i)
		string[x++] = s1[i++];
	string[x] = '\0';
	return (string);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*string;

	i = 0;
	if (!set || !*set)
		return (ft_strdup(s1));
	if (!s1)
		return (NULL);
	while (s1[i] && ft_is_set(s1[i], set))
		i++;
	j = ft_strlen(s1) - 1;
	while (j > i && s1[j] && ft_is_set(s1[j], set))
		j--;
	if (j < i)
		return (ft_strdup(""));
	j++;
	string = malloc(sizeof(char) * (j - i) + 1);
	return (ft_build_string(string, s1, i, j));
}

/*int	main(void)
{
	const char *s1;
	const char *set;

	s1 = "XYZXYYWa fred e lindaZWWWXY";
	set = "XYZWK";
	printf("%s", ft_strtrim(s1, set));
}*/
