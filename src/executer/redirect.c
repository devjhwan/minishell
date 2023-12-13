/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinel <jmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:42:19 by jmarinel          #+#    #+#             */
/*   Updated: 2023/12/13 16:52:55 by jmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

static void	get_redir(t_io *redir, t_fdp *fdp);
static t_io	*here_doc(t_io *redir, char *limiter);

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

static void	get_redir(t_io *redir, t_fdp *fdp)
{
	if (redir->type == IN)
		fdp->tmp_in = redir;
	else if (redir->type == HERE_DOC)
		fdp->tmp_in = here_doc(redir, redir->file);
	if (redir->type == OUT || redir->type == OUT_APPEND)
	{
		fdp->tmp_out = redir;
		open_outfile(fdp);
		//donde los cierro?
	}
}

static t_io	*here_doc(t_io *redir, char *limiter)
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
	free(redir->file);
	redir->file = ft_strdup("/tmp/here_doc");
	if (redir->file == NULL)
		ft_error(0, 0, NULL);
	return (redir);
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
