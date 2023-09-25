/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pipex_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-f <fgomes-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 12:01:47 by fgomes-f          #+#    #+#             */
/*   Updated: 2023/09/23 14:21:40 by fgomes-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//this function checks if there is an error;
//functions like access or pipe return -1 when an error occur,
//that's why print the error message if the value is -1;
//with this function, if there is an error:
//we print in the standard error (fd 2) an error message,
//and then we use perror
//to have the details about where was the error (string), 
//and what was the error.

void	check_for_errors(int value, char *string)
{
	if (value == -1)
	{
		ft_putstr_fd("pipex: ", STDERR_FILENO);
		perror(string);
		exit(EXIT_FAILURE);
	}
	return ;
}
//this function is called if we use heredoc;
//we use it to open the heredoc,
//(read only, create if necessary, erase if necessary)
//we also use printf to print "heredoc >";
//and then we use gnl to read from stdin (fd0)
//and return the line we write on the terminal;
//then we use a while: we save that line in the heredoc,
//we print "heredoc>" again,
//we free the line so we can use it again,
//and we call get next line...
//until we see our limit;
//when we leave the while we close the heredoc.

void	ft_heredoc(char	*limit)
{
	int		hd_fd;
	char	*line;

	hd_fd = open("here_doc", O_RDWR | O_TRUNC | O_CREAT, 0644);
	ft_printf("heredoc> ");
	line = get_next_line(0);
	while (((ft_strncmp(line, limit, ft_strlen(limit)) != 0) && line)
		|| (ft_strclen(line, '\n') != ft_strlen(limit)))
	{
		ft_putstr_fd(line, hd_fd);
		ft_printf("heredoc> ");
		free(line);
		line = get_next_line(0);
	}
	free(line);
	close(hd_fd);
}

//this function is used to shorten the path function.
//we look for "PATH=" on envp because we need that line
//and we delete those first five characters
//and save the rest in no_filtered_path;
//then we use split to create an array of strings
//without the ":";
//and we sent this array to the path function.

char	**split_the_path(char **envp)
{
	int		i;
	char	*no_filtered_path;
	char	**splited_path;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			no_filtered_path = ft_substr(envp[i], 5, (ft_strlen(envp[i]) - 5));
			splited_path = ft_split(no_filtered_path, ':');
			if (splited_path == NULL)
				return (NULL);
			free (no_filtered_path);
			return (splited_path);
		}
		i++;
	}
	return (NULL);
}
