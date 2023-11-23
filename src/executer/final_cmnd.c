/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_cmnd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinel <jmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:10:36 by jmarinel          #+#    #+#             */
/*   Updated: 2023/11/23 15:38:55 by jmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

void	final_cmnd(t_fdp *fdp, t_cmnd *list, t_minishell *shell, char *cmnd)
{
	if (fdp->tmp_in)
	{
		if (fdp->tmp_in->type == IN || fdp->tmp_in->type == HERE_DOC)
			dup_and_close(fdp->fd_file[INF], STDIN_FILENO);
	}
	else
		dup_and_close(fdp->fd_pipe[0], STDIN_FILENO);
	if (fdp->tmp_out)
	{
		if (fdp->tmp_out->type == OUT || fdp->tmp_out->type == OUT_APPEND)
			dup_and_close(fdp->fd_file[OUTF], STDOUT_FILENO);
	}
	else
		dup_and_close(fdp->dup_stdout, STDOUT_FILENO);
	close(fdp->dup_stdin);
	fdp->pid[fdp->i] = fork();
	if (fdp->pid[fdp->i] == 0)
		child(shell->_envp, fdp, list->args, cmnd);
}
