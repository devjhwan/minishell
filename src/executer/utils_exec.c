/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:22:39 by jmarinel          #+#    #+#             */
/*   Updated: 2023/12/04 18:36:47 by junghwle         ###   ########.fr       */
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
		fprintf(stderr, "bash: Invalid number of arguments\n");
	else if (err == ERR_MC)
		fprintf(stderr, "bash: error trying to allocate memory\n");
	else if (err == ERR_CNF)
		fprintf(stderr, "minishell: command not found\n");
	else if (err == ERR_NFD)
		fprintf(stderr, "minishell: No such file or directory\n");
	else if (err == ERR_PERM)
		fprintf(stderr, "minishell: permission denied\n");
	else if (err == ERR_PERR)
		perror("bash: ");
	return (ext);
}
