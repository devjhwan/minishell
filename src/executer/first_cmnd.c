/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_cmnd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinel <jmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:10:33 by jmarinel          #+#    #+#             */
/*   Updated: 2023/11/23 16:31:54 by jmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

void	first_cmnd(t_fdp *fdp, t_cmnd *list, t_minishell *shell, char *cmnd)
{
	if (fdp->cmnd_cnt == 1)
		only_cmnd(fdp, list, shell, cmnd);
	else
	{
		if (pipe(fdp->fd_pipe) == -1)
			ft_error(0, 0, NULL);
		set_redir_in(fdp);
		if (fdp->tmp_out)
			set_redir_out(fdp);
		else if (fdp->cmnd_cnt > 1)
			dup_and_close(fdp->fd_pipe[1], STDOUT_FILENO);
		fdp->pid[fdp->i] = fork();
		if (fdp->pid[fdp->i] == 0)
			child(shell->_envp, fdp, list->args, cmnd);
	}
}

void	only_cmnd(t_fdp *fdp, t_cmnd *list, t_minishell *shell, char *cmnd)
{
	set_redir_in(fdp);
	set_redir_out(fdp);
	if (check_builtin(list) == 0)
	{
		fdp->pid[fdp->i] = fork();
		if (fdp->pid[fdp->i] == 0)
			child(shell->_envp, fdp, list->args, cmnd);
	}
	else
	{
		//else manage builtin
		restore_io(fdp);
	}
}
