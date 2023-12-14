/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinel <jmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:29:55 by junghwle          #+#    #+#             */
/*   Updated: 2023/12/14 13:01:24 by jmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"
#include "err_msg.h"

int	is_directory(char *file)
{
	struct stat	file_info;

	if (stat(file, &file_info) == 0)
	{
		if (S_ISDIR(file_info.st_mode))
		{
			ft_printf_fd(2, "minishell: %s: ",file);
			ft_printf_fd(2, "Is a directory\n");
			return (ERROR);
		}
	}
	return (SUCCESS);
}

int	manage_files(t_fdp	*fdp)
{
	int	ret;

	ret = SUCCESS;
	if (fdp->tmp_in && fdp->tmp_in->type)
		ret = open_infile(fdp);
	if (ret == SUCCESS && fdp->tmp_out && fdp->tmp_out->type)
		ret = open_outfile(fdp);
	return (ret);
}

int	open_infile(t_fdp *fdp)
{
	if (access(fdp->tmp_in->file, F_OK) != 0)
		return (ft_perror(NO_FILE_OR_DIRECTORY, fdp->tmp_in->file), ERROR);
	if (access(fdp->tmp_in->file, R_OK) != 0)
		return (ft_perror(PERMISSION_DENIED, fdp->tmp_in->file), ERROR);
	fdp->fd_file[INF] = open(fdp->tmp_in->file, O_RDONLY);
	return (SUCCESS);
}

int	open_outfile(t_fdp *fdp)
{
	if (access(fdp->tmp_out->file, F_OK) == 0)
	{
		if (access(fdp->tmp_out->file, W_OK) != 0)
			return (ft_perror(PERMISSION_DENIED, fdp->tmp_out->file), ERROR);
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
	return (SUCCESS);
}
