/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemanet <hdemanet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:23:21 by hdemanet          #+#    #+#             */
/*   Updated: 2024/07/31 10:37:34 by hdemanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* Displays a system error message and terminates the program with an error. */
void	exit_error(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}

/* Displays a custom error message. */
void	custom_error(char *header, char *msg)
{
	ft_putstr_fd(header, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
}

/* Frees the memory allocated for an array of strings. */
void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

/* Finds the full path of the command from the PATH environment variable. */
char	*get_cmd_path(char *cmd, char **envp)
{
	char	**envp_paths;
	char	*cmd_path;
	int		i;
	char	*only_path;

	i = 0;
	while (!ft_strnstr(envp[i], "PATH=", 5))
		i++;
	envp_paths = ft_split(envp[i] + 5, ':');
	i = -1;
	while (envp_paths[++i])
	{
		only_path = ft_strjoin(envp_paths[i], "/");
		cmd_path = ft_strjoin(only_path, cmd);
		free (only_path);
		if (access(cmd_path, F_OK) == 0)
		{
			free_split(envp_paths);
			return (cmd_path);
		}
		free(cmd_path);
	}
	free_split(envp_paths);
	custom_error(cmd, "command not found");
	return (NULL);
}

/* Executes the specified command with given arguments and environment. */
void	run_cmd(char *cmd, char **envp)
{
	char	**cmd_and_flags;
	char	*path;

	cmd_and_flags = ft_split(cmd, ' ');
	path = get_cmd_path(cmd_and_flags[0], envp);
	if (!path)
	{
		free_split(cmd_and_flags);
		free (path);
		exit(127);
	}
	if (execve(path, cmd_and_flags, envp) == -1)
	{
		free_split(cmd_and_flags);
		free (path);
		exit_error();
	}
}
