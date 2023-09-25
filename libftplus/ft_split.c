/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-f <fgomes-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:11:46 by fgomes-f          #+#    #+#             */
/*   Updated: 2023/05/09 12:56:51 by fgomes-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] != c)
			j++;
		while (s[i] && s[i] != c)
			i++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (j);
}

static size_t	ft_count_letters(char const *s, char c, size_t j)
{
	size_t	x;
	size_t	i;
	size_t	y;

	x = 0;
	i = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i] && x != j)
	{
		if (s[i] != c)
			x++;
		while (s[i] && s[i] != c)
			i++;
		while (s[i] && s[i] == c)
			i++;
	}
	y = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		y++;
	}
	return (y);
}

static char	**put_words(char **array, size_t n_of_words, const char *s, char c)
{
	size_t	i;
	size_t	x;
	size_t	j;

	i = 0;
	x = 0;
	while (i < n_of_words)
	{
		j = 0;
		while (s[x] && s[x] == c)
			x++;
		while (s[x] && s[x] != c)
		{
			array[i][j] = s[x];
			x++;
			j++;
		}
		array[i][j] = '\0';
		i++;
	}
	array[n_of_words] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	char	**array;
	size_t	n_of_words;

	i = 0;
	n_of_words = ft_count_words(s, c);
	array = malloc(sizeof(char *) * (n_of_words + 1));
	if (!array)
		return (NULL);
	while (i < n_of_words)
	{
		array[i] = malloc(sizeof(char) * (ft_count_letters(s, c, i) + 1));
		i++;
	}
	i = 0;
	return (put_words(array, n_of_words, s, c));
}

/*int	main(void)
{
	size_t	i;
	char	*s1;
	char	c;
	char	**test;

	c = ' ';
	s1 = "     ";
//	s1 = "array b carro";
	test = ft_split(s1, c);
	i = 0;
//	printf("%s\n", test[i]);
	while (i <= ft_count_words(s1, c))
	{
		printf("%s\n", test[i]);
		i++;
	}
}*/
