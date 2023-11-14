/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_cmnd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinel <jmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:10:33 by jmarinel          #+#    #+#             */
/*   Updated: 2023/11/14 20:11:13 by jmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

void	first_cmnd(t_fdp *fdp, t_cmnd *list, t_minishell *shell, char *cmnd)
{
	if (pipe(fdp->fd_pipe) == -1)
		ft_error(0, 0, NULL);
	if (fdp->tmp_in->type == IN || fdp->tmp_in->type == HERE_DOC)
		dup_and_close(fdp->fd_file[INF], STDIN_FILENO);
	if (fdp->tmp_out->type == OUT || fdp->tmp_out->type == OUT_APPEND)
		dup_and_close(fdp->fd_file[OUTF], STDOUT_FILENO);
	else
		dup_and_close(fdp->fd_pipe[1], STDOUT_FILENO);
	fdp->pid[fdp->i] = fork();
	if (fdp->pid[fdp->i] == 0)
		child(shell->_envp, fdp, list->args, cmnd);

}

