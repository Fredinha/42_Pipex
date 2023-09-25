/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-f <fgomes-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:38:43 by fgomes-f          #+#    #+#             */
/*   Updated: 2023/09/21 12:34:53 by fgomes-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_split_free(char **array_of_strings)
{
	int	i;

	i = 0;
	while (array_of_strings[i])
	{
		free (array_of_strings[i]);
		i++;
	}
	free (array_of_strings);
}
