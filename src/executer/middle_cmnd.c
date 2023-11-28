/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middle_cmnd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinel <jmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:10:39 by jmarinel          #+#    #+#             */
/*   Updated: 2023/11/23 16:27:38 by jmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

void	middle_cmnd(t_fdp *fdp, t_cmnd *list, t_minishell *shell, char *cmnd)
{
	if (fdp->tmp_in)
		set_redir_in(fdp);
	else
		dup_and_close(fdp->pipes[fdp->i - 1].fd[READ], STDIN_FILENO);
	if (fdp->tmp_out)
		set_redir_out(fdp);
	else
		dup_and_close(fdp->pipes[fdp->i].fd[WRTE], STDOUT_FILENO);
	child(shell->_envp, fdp, list->args, cmnd);
}
