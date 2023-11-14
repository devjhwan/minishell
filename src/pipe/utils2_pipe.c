/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:29:24 by jmarinel          #+#    #+#             */
/*   Updated: 2023/11/14 01:15:12 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe.h"

int	init_data(t_fdp *fdp, t_cmnd *cmnd_list)
{
	fdp->cmnd_cnt = ft_lst_size(cmnd_list);
	fdp->dup_stdin = dup(STDIN_FILENO);
	fdp->dup_stdout = dup(STDOUT_FILENO);
	fdp->pid = malloc (sizeof(int) * fdp->cmnd_cnt);
	if (!fdp->pid)
		return (1);
	fdp->lim = NULL;
	return (0);
}

int	ft_dup_close(int fd_to, int fd_from)
{
	if (dup2(fd_to, fd_from) == -1)
		return (-1);
	if (close(fd_to) == -1)
		return (-1);
	return (0);
}

void	ft_free_array(char **arr, int i)
{
	while (i >= 0)
	{
		free(arr[i]);
		i--;
	}
	free(arr);
}

/* 
t_fdp	ft_init_fdp(t_fdp *fdp, int argc, char **argv)
{
	fdp->cmnd_cnt = ft_lstsize(fdp->cmnd_list);

	if (!ft_strncmp(argv[1], "here_doc", 10))
	{
		fdp.hd = 1;
		fdp.cnt = argc - 4;
		fdp.lim = argv[2];
		fdp.pid = malloc (sizeof(int) * argc - 4);
	}
	else
	{
		fdp.hd = 0;
		fdp.cnt = argc - 3;
		fdp.lim = NULL;
		fdp.pid = malloc (sizeof(int) * argc - 3);
	}
	if (!fdp.pid)
	{
		ft_error(ERR_MC, 2, NULL);
		exit(1);
	}
	fdp.argv = NULL;
	fdp.io = NULL;
	fdp.io = check_files(argv, argc, fdp.hd, fdp.io);
	return (fdp.i = 0, fdp);
} */
