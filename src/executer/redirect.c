/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:42:19 by jmarinel          #+#    #+#             */
/*   Updated: 2023/12/03 23:59:47 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

int	redirect(t_io *redir, t_fdp *fdp)
{
	fdp->tmp_in = NULL;
	fdp->tmp_out = NULL;
	if (redir && redir->type)
	{
		while (redir != NULL)
		{
			get_redir(redir, fdp);
			redir = redir->next;
		}
		if (manage_files(fdp))
			return (1);
	}
	return (0);
}

void	get_redir(t_io *redir, t_fdp *fdp)
{
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
	if (fdp->tmp_in != NULL && \
		dup_and_close(fdp->fd_file[INF], STDIN_FILENO) == -1)
		return (ERROR);
	return (SUCCESS);
}

int	set_redir_out(t_fdp	*fdp)
{
	if (fdp->tmp_out != NULL && \
		dup_and_close(fdp->fd_file[OUTF], STDOUT_FILENO) == -1)
		return (ERROR);
	return (SUCCESS);
}
