/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomes-f <fgomes-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:23:49 by fgomes-f          #+#    #+#             */
/*   Updated: 2023/09/22 16:46:24 by fgomes-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

//this function returns the exact path to the cmd;
//it takes the main command and envp;
//some variables are created to help the process;
//we call the split_the_path function to get rid of the ":",
//and that function returns an array of strings
//that we can test to get the right path;
//while we still have strigs in that array,
//we test each string with "/" and the cmd
//until we get the correct path;
//when the path gives us access to the cmd file
//it's because it's the right one so we return it;
//and we free the memory used in the process.

char	*get_the_right_path(char *command, char **envp)
{
	char	*path_in_process;
	char	*path;
	char	**splited_path;
	int		i;

	i = 0;
	splited_path = split_the_path(envp);
	while (splited_path[i])
	{
		path_in_process = ft_strjoin(splited_path[i], "/");
		path = ft_strjoin(path_in_process, command);
		free (path_in_process);
		if (access(path, F_OK) == 0)
			return (path);
		free (path);
		i++;
	}
	i = 0;
	ft_split_free(splited_path);
	return (NULL);
}

//this function is used to run the commands
//passed as arguments.
//this function will be called twice:
//fist in the child process, to execute the first command,
//and then in the main, to execute the second commmand;
//we create an array of strings and we use split 
//to separate the main command and the options,
//for example: "cat -e" turn into "cat" "-e".
//then we take the first element of the array ("cat")
//and we send it to the path function,
//that function gets the path to that command
//and returns a string with the exact path;
//then check for errors on envp or on the path;
//then we use execve to execute the cmd;
//execve shuts the program down;
//and we check for errors one last time
//to make sure execve worked.

void	run_command(char *command, char **envp)
{
	char	**arguments_of_command;
	char	*path_to_command;

	arguments_of_command = ft_split(command, ' ');
	path_to_command = get_the_right_path(arguments_of_command[0], envp);
	if (envp == NULL || path_to_command == NULL)
	{
		dup2(STDERR_FILENO, STDOUT_FILENO);
		ft_printf("pipex: %s: command not found\n", arguments_of_command[0]);
		if (path_to_command)
			free(path_to_command);
		if (arguments_of_command)
			ft_split_free(arguments_of_command);
		exit(127);
	}
	execve(path_to_command, arguments_of_command, envp);
	dup2(STDERR_FILENO, STDOUT_FILENO);
	ft_printf("pipex: %s: command not found\n", arguments_of_command[0]);
	ft_split_free(arguments_of_command);
	free(path_to_command);
	exit(127);
}

//in this function we use fork and give instructions to child and parent.
//create an id to use in fork:
//if id is 0 we are on the child process,
//if we are in the parent process, id will be the child's process id;
//create array of 2 ints to use in the pipe function;
//we check for errors both the pipe and the fork;
//in the child process (id = 0) we check file1 for errors,
//close the reading end of the pipe,
//and use dup2 to redirect the fd1 to our pipe,
//then we call the run_command function to run the first command;
//in the parent process, we close the writing end of the pipe, 
//and redirect the fd0 to the pipe,
//and we use waitpid to wait for the child process;
//The waitpid can receive null (it ignores the child's return status),
//and WNOHANG means that the function returns 
//immediately if no child has exited.

void	do_the_fork_thing(char *file1, char *command1, char **envp)
{
	int	id;
	int	pipefd[2];

	check_for_errors(pipe(pipefd), "pipe");
	id = fork();
	if (id == -1)
		check_for_errors(id, "fork");
	else if (id == 0)
	{
		check_for_errors(access(file1, R_OK), file1);
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		run_command(command1, envp);
	}
	else
	{
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		waitpid(id, NULL, WNOHANG);
	}
}

//check if there are five arguments:
//if not, print an error message;
//if yes, open the 2 files passed as arguments:
//file1 read only,
//file2 write, create if necessary, erase if necessary;
//save their fds in fdin and fdout;
//use utils function to check for errors;
//use dup2 to redirect stdin and stout to our files;
//call the fork function to run cmd1 on child;
//call function to run command on parent.

int	main(int argc, char **argv, char **envp)
{
	int	fdin;
	int	fdout;

	if (argc == 5)
	{
		fdin = open(argv[1], O_RDONLY);
		fdout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		check_for_errors(access(argv[4], W_OK), argv[4]);
		dup2(fdin, STDIN_FILENO);
		dup2(fdout, STDOUT_FILENO);
		do_the_fork_thing(argv[1], argv[2], envp);
		run_command(argv[3], envp);
	}
	else
	{
		ft_printf("Usage:./pipex infile cmd1 cmd2 outfile\n");
	}
	return (1);
}
