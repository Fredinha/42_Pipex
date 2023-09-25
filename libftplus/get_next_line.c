/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-f <fgomes-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 14:58:55 by fgomes-f          #+#    #+#             */
/*   Updated: 2023/09/11 16:57:14 by fgomes-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*read_file(int fd, char *stash)
{
	char	*buf;
	int		n_bytes_read;

	n_bytes_read = 1;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (!ft_strchr_gnl(stash, '\n') && n_bytes_read != 0)
	{
		n_bytes_read = read(fd, buf, BUFFER_SIZE);
		if (n_bytes_read == -1)
		{
			free (buf);
			free (stash);
			return (NULL);
		}
		buf[n_bytes_read] = '\0';
		if (!buf)
			return (NULL);
		stash = ft_strjoin_gnl(stash, buf);
	}
	free (buf);
	return (stash);
}

char	*get_the_line(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\0')
		line = malloc(sizeof(char) * (i + 1));
	else
		line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*save_leftovers(char *stash)
{
	int		i;
	int		j;
	char	*new_line;

	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	new_line = malloc(sizeof(char) * (ft_strlen_gnl(stash) - i + 1));
	if (!new_line)
		return (NULL);
	i++;
	while (stash[i])
		new_line[j++] = stash[i++];
	new_line[j] = '\0';
	free (stash);
	return (new_line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash[MAX_FILES];

	if (fd < 0 || fd > MAX_FILES || BUFFER_SIZE <= 0)
		return (NULL);
	stash[fd] = read_file(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = get_the_line(stash[fd]);
	stash[fd] = save_leftovers(stash[fd]);
	return (line);
}

/*int	main(void)
{
	char	*string;
	int	fd1;
	int	fd2;
	int	fd3;

	fd1 = open("test1.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	fd3 = open("test3.txt", O_RDONLY);

	string = get_next_line(fd1);
	printf("this is the first line from the english file: %s\n", string);
	free(string);
	string = get_next_line(fd2);
	printf("this is the first line from the portuguese file: %s\n", string);
	free(string);
	string = get_next_line(fd3);
	printf("this is the first line from the digit file: %s\n", string);
	free(string);
	string = get_next_line(fd1);
	printf("this is the second line from the english file: %s\n", string);
	free(string);
	string = get_next_line(fd1);
	printf("this is the third line from the english file: %s\n", string);
	free(string);
	string = get_next_line(fd1);
	printf("this is the fourth line from the english file: %s\n", string);
	free(string);
	string = get_next_line(fd3);
	printf("this is the second line from the digit file: %s\n", string);
	free(string);
	string = get_next_line(fd2);
	printf("this is the second line from the portuguese file: %s\n", string);
	free(string);
	string = get_next_line(fd2);
	printf("this is the third line from the portuguese file: %s\n", string);
	free(string);
	string = get_next_line(fd3);
	printf("this is the third line from the digit file: %s\n", string);
	free(string);
	string = get_next_line(fd3);
	printf("this is the fourth line from the digit file: %s\n", string);
	free(string);
	string = get_next_line(fd2);
	printf("this is the fourth line from the portuguese file: %s\n", string);
	free(string);
	string = get_next_line(fd2);
	printf("this is the fifth line from the portuguese file: %s\n", string);
	free(string);
	string = get_next_line(fd3);
	printf("this is the fifth line from the digit file: %s\n", string);
	free(string);
	string = get_next_line(fd1);
	printf("this is the fifth line from the portuguese file: %s\n", string);
	free(string);
	return (0);
}*/
