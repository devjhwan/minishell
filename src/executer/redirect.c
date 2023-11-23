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

void	manage_files(t_fdp	*fdp)
{
	if (fdp->tmp_in && fdp->tmp_in->type)
	{
		if (access(fdp->tmp_in->file, F_OK | R_OK) != 0)
			ft_error(0, 0, NULL);
		else
			fdp->fd_file[INF] = open(fdp->tmp_in->file, O_RDONLY);
	}
	if (fdp->tmp_out && fdp->tmp_out->type)
		open_outfile(fdp);
}

void	open_outfile(t_fdp *fdp)
{
	if (access(fdp->tmp_out->file, F_OK) == 0)
	{
		if (access(fdp->tmp_out->file, W_OK) != 0)
			ft_error(0, 0, NULL);
		else if (fdp->tmp_out->type == OUT_APPEND)
			fdp->fd_file[OUTF]
				= open(fdp->tmp_out->file, O_WRONLY | O_APPEND, 0644);
		else if (fdp->tmp_out->type == OUT)
			fdp->fd_file[OUTF]
				= open(fdp->tmp_out->file, O_WRONLY | O_TRUNC, 0644);
	}
	else
		fdp->fd_file[OUTF]
			= open(fdp->tmp_out->file, O_WRONLY | O_CREAT, 0644);
}

t_io	*here_doc(t_io *redir, char *limiter)
{
	char	*line;
	int		fd;

	fd = open("/tmp/here_doc", O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (fd == -1)
		ft_error(0, 0, NULL);
	line = readline("> ");
	while (line && ft_strncmp(limiter, line, ft_strlen(limiter)) != 0)
	{
		line = ft_strjoin_line(line, "\n");
		ft_putstr_fd(line, fd);
		free(line);
		line = readline("> ");
	}
	close (fd);
	free(line);
	redir->file = "/tmp/here_doc";
	return (redir);
}
