/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-f <fgomes-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:12:13 by fgomes-f          #+#    #+#             */
/*   Updated: 2023/09/23 14:19:54 by fgomes-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strclen(const char *s, char c)
{
	size_t	size_of_string;

	size_of_string = 0;
	while (s && s[size_of_string] && s[size_of_string] != c)
		size_of_string++;
	return (size_of_string);
}
