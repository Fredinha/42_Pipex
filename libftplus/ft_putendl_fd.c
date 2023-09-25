/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:45:13 by fgomes-f          #+#    #+#             */
/*   Updated: 2023/05/11 21:35:45 by fgomes-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t	len;

	len = ft_strlen(s);
	write(fd, s, len);
	write (fd, "\n", 1);
}

/*int	main(void)
{
	char s[5] = "abc";
	int	fd;

	fd = 1;
	ft_putendl_fd(s, fd);
	//printf("%s", s);
}*/
