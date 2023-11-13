/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_cmnd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinel <jmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:10:33 by jmarinel          #+#    #+#             */
/*   Updated: 2023/11/13 17:03:23 by jmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe.h"

void	first_cmnd(t_fdp *fdp, t_cmnd *cmnd_list, t_minishell *shell)
{
	if (fdp->tmp_in->type == IN || fdp->tmp_in->type == HERE_DOC)
		dup_and_close(fdp->fd_file[INF], STDOUT_FILENO);
	if (fdp->tmp_in->type == OUT || fdp->tmp_in->type == OUT_APPEND)
		dup_and_close(fdp->fd_file[OUTF], STDOUT_FILENO);
	else
	{
		if (pipe(fdp->fd_pipe) == -1)
			return (-1);
		dup_and_close(fdp->fd_pipe[1], STDOUT_FILENO);
		fdp->pid[fdp->i] = fork();
		if (fdp->pid[fdp->i] == 0)
			child(shell->_envp, fdp, cmnd_list->args);
	}
}
