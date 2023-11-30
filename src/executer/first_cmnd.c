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

int	first_cmnd(t_fdp *fdp, t_cmnd *list, t_minishell *shell, char **path)
{
	set_redir_in(fdp);
	if (fdp->tmp_out)
		set_redir_out(fdp);
/* 	else if (fdp->cmnd_cnt > 1)
	{
		dup_and_close(fdp->pipes[fdp->i].fd[WRTE], STDOUT_FILENO);
		close(fdp->pipes[fdp->i].fd[READ]);
	} */
	if (fdp->cmnd_cnt > 1)
		dup_and_close(fdp->pipe[1], STDOUT_FILENO);
	if (check_builtin(list))
	{
		exec_builtin(shell, shell->cmnd_list);
		restore_io(fdp);
		return (0);
	}
	else
	{
		//fprintf(stderr, "\npath es %s\n i fdp.i es: %i\n", path[fdp->i], fdp->i);
		child(shell->_envp, fdp, list->args, path[fdp->i]);
	}
	return (1);
}

int	only_cmnd(t_fdp *fdp, t_cmnd *list, t_minishell *shell)
{
	char** path;

	(void)path;
	set_redir_in(fdp);
	set_redir_out(fdp);
	exec_builtin(shell, list);
	restore_io(fdp);
	return (0);
}
