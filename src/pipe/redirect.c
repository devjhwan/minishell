/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinel <jmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:42:19 by jmarinel          #+#    #+#             */
/*   Updated: 2023/11/13 15:27:44 by jmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe.h"

int	redirect(t_io *redir, t_fdp *fdp)
{
	if (redir->type)
	{
		while (redir)
		{
			get_redir(redir, fdp);
			redir = redir->next;
		}
		manage_files(fdp);
		return (0);
	}
}

void	manage_files(t_fdp	*fdp)
{
	if (fdp->tmp_in->type)
	{
		if (access(fdp->tmp_in->file, F_OK | R_OK) != 0)
			return (-1);
		fdp->fd_file[INF] = open(fdp->tmp_in->file, O_RDONLY);
	}
	if (fdp->tmp_out->type)
		open_outfile(fdp);
}

void	get_redir(t_io *redir, t_fdp *fdp)
{
	if (redir->type == IN)
		fdp->tmp_in = redir;
	if (redir->type == HERE_DOC)
		here_doc(redir);
	if (redir->type == OUT
		|| redir->type == OUT_APPEND)
	{
		fdp->tmp_out = redir;
		open_outfile(fdp);
		close(fdp->fd_file[OUTF]);
	}
}

void	open_outfile(t_fdp *fdp)
{
	if (access(fdp->tmp_out->file, F_OK) == 0)
	{
		if (access(fdp->tmp_out->file, W_OK) != 0)
			return (-1);
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

int	here_doc(t_io *redir)
{
	char	*line;
	int		fd;

	fd = open("/tmp/here_doc_pipex", O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (fd == -1)
		return (-1);
	dup2(fd, STDOUT_FILENO);
	line = get_next_line(0);
	while (ft_strncmp(line, argv[2], ft_strlen(argv[2])))
	{
		ft_putstr_fd(line, fd);
		free(line);
		line = get_next_line(0);
	}
	free(line);
	close (fd);
	fd = open("/tmp/here_doc_pipex", O_RDONLY, 0644);
	return (fd);
}