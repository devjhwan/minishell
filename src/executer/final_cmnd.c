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

int	final_cmnd(t_fdp *fdp, t_cmnd *list, t_minishell *shell)
{
	char** path;

	path = NULL;
	if (fdp->tmp_in)
		set_redir_in(fdp);
	else
		dup_and_close(fdp->pipes[fdp->i - 1].fd[READ], STDIN_FILENO);
	if (fdp->tmp_out)
		set_redir_out(fdp);
	else
		dup_and_close(fdp->std_in_out[WRTE], STDOUT_FILENO);
	if (check_builtin(list))
	{
		exec_builtin(shell, shell->cmnd_list);
		restore_io(fdp);
		return (0);
	}
	else
	{
		path = init_path(fdp, list->args, shell->_envp, 0);
		child(shell->_envp, fdp, list->args, path[0]);
	}
	//close(fdp->std_in_out[READ]);
	return (1);
}
