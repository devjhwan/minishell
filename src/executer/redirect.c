/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinel <jmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:42:19 by jmarinel          #+#    #+#             */
/*   Updated: 2023/11/23 12:36:02 by jmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

int	redirect(t_io *redir, t_fdp *fdp, t_minishell *shell)
{
	if (redir && redir->type)
	{
		while (redir != NULL)
		{
			get_redir(redir, fdp, shell->cmnd_list->args);
			redir = redir->next;
		}
		manage_files(fdp);
	}
	return (0);
}

void	get_redir(t_io *redir, t_fdp *fdp, char **args)
{
	(void) args;
	if (redir->type == IN)
		fdp->tmp_in = redir;
	else if (redir->type == HERE_DOC)
		fdp->tmp_in = here_doc(redir, redir->file);
	if (redir->type == OUT \
		|| redir->type == OUT_APPEND)
	{
		fdp->tmp_out = redir;
		open_outfile(fdp);
		close(fdp->fd_file[OUTF]);
	}
}

int	set_redir_in(t_fdp	*fdp)
{
	if (fdp->tmp_in)
	{
		if (fdp->tmp_in->type == IN || fdp->tmp_in->type == HERE_DOC)
		{
			dup_and_close(fdp->fd_file[INF], STDIN_FILENO);
			return(1);
		}
	}
	return (0);
}

int	set_redir_out(t_fdp	*fdp)
{
	if (fdp->tmp_out)
	{
		if (fdp->tmp_out->type == OUT || fdp->tmp_out->type == OUT_APPEND)
		{
			dup_and_close(fdp->fd_file[OUTF], STDOUT_FILENO);
			return (1);
		}
	}
	return (0);
}
