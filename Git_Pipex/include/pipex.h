/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemanet <hdemanet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:23:39 by hdemanet          #+#    #+#             */
/*   Updated: 2024/07/31 10:35:07 by hdemanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <signal.h>

void	sub_process(int *fd, char **argv, char **envp);
void	main_process(int *fd, char **argv, char **envp);
void	exit_error(void);
void	custom_error(char *header, char *msg);
void	free_split(char **str);
char	*get_cmd_path(char *cmd, char **envp);
void	run_cmd(char *cmd, char **envp);

#endif