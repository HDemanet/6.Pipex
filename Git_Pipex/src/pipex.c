/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemanet <hdemanet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:48:40 by hdemanet          #+#    #+#             */
/*   Updated: 2024/07/31 10:37:32 by hdemanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* Checks if the PATH environment variable is set and non-empty. */
void	check_envp(char **envp)
{
	int	i;
	int	check;

	i = -1;
	check = 0;
	while (envp[++i])
		if (ft_strnstr(envp[i], "PATH=", 5) && envp[i][6])
			check = 1;
	if (!check)
	{
		custom_error("Error", "The environment PATH has no values.");
		exit(1);
	}
}

/* Executes the first command with input from a file and output to a pipe. */
void	sub_process(int *fd, char **argv, char **envp)
{
	int	fd_in;

	fd_in = open(argv[1], O_RDONLY, 0777);
	if (fd_in == -1)
		exit_error();
	dup2(fd[1], STDOUT_FILENO);
	dup2(fd_in, STDIN_FILENO);
	close(fd[0]);
	run_cmd(argv[2], envp);
}

/* Executes the second command with input from a pipe and output to a file. */
void	main_process(int *fd, char **argv, char **envp)
{
	int	fd_out;

	fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd_out == -1)
		exit_error();
	dup2(fd[0], STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	close(fd[1]);
	run_cmd(argv[3], envp);
}

/*Main function that sets up the pipe, forks processes, and runs the pipeline.*/
int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	check_envp(envp);
	if (argc == 5)
	{
		if (pipe(fd) == -1)
			exit_error();
		pid = fork();
		if (pid == -1)
			exit_error();
		if (pid == 0)
			sub_process(fd, argv, envp);
		waitpid(pid, NULL, 0);
		main_process(fd, argv, envp);
	}
	else
	{
		custom_error("Error", "Wrong number of arguments");
		custom_error("Correct Input", "./pipex <file1> <cmd1> <cmd2> <file2>");
		exit(1);
	}
	return (0);
}
