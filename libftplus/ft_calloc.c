/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 14:49:52 by fgomes-f          #+#    #+#             */
/*   Updated: 2023/05/08 12:59:51 by fgomes-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*pointer;

	pointer = malloc(nmemb * size);
	if (pointer == NULL)
		return (NULL);
	ft_bzero(pointer, size * nmemb);
	return (pointer);
}

/*int	main(void)
{
	char	*pointer;

//	pointer = calloc(5, sizeof(char));
//	printf("%s\n", pointer);
//	printf("%c\n", pointer[0]);
//
	pointer = ft_calloc(5, sizeof(char));
	printf("%s\n", pointer);
	printf("%c\n", pointer[0]);
}*/
