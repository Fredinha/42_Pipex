/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pipex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-f <fgomes-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:51:30 by fgomes-f          #+#    #+#             */
/*   Updated: 2023/09/22 12:17:49 by fgomes-f         ###   ########.fr       */
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
