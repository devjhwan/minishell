/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinel <jmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:22:39 by jmarinel          #+#    #+#             */
/*   Updated: 2023/12/13 17:45:51 by jmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

int	restore_io(t_fdp *fdp)
{
	if (dup2(fdp->std_in_out[0], STDIN_FILENO) == -1)
		return (1);
	if (dup2(fdp->std_in_out[1], STDOUT_FILENO) == -1)
		return (1);
	return (0);
}

void	close_fds(t_fdp *fdp)
{
	if (fdp->fd_file[0])
		close (fdp->fd_file[0]);
	if (fdp->fd_file[1])
		close (fdp->fd_file[1]);
}

int	ft_error(int err, int ext, char *cmd)
{
	(void)cmd;
	if (err == ERR_ARG)
		ft_printf_fd(2, "bash: Invalid number of arguments\n");
	else if (err == ERR_MC)
		ft_printf_fd(2, "bash: error trying to allocate memory\n");
	else if (err == ERR_CNF)
		ft_printf_fd(2, "minishell: command not found\n");
	else if (err == ERR_NFD)
		ft_printf_fd(2, "minishell: No such file or directory\n");
	else if (err == ERR_PERM)
		ft_printf_fd(2, "minishell: permission denied\n");
	else if (err == ERR_PERR)
		perror("bash: ");
	return (ext);
}
