/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_exec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:29:24 by jmarinel          #+#    #+#             */
/*   Updated: 2023/12/04 19:07:44 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

static	int	ft_list_size(t_cmnd *cmnd_list)
{
	int	i;

	i = 0;
	while (cmnd_list)
	{
		cmnd_list = cmnd_list->next;
		i++;
	}
	return (i);
}

int	init_data(t_fdp *fdp, t_cmnd *cmnd_list, char **_envp)
{
	(void)_envp;
	ft_bzero((void *)fdp, sizeof(t_fdp));
	fdp->cmnd_cnt = ft_list_size(cmnd_list);
	fdp->std_in_out[0] = dup(STDIN_FILENO);
	fdp->std_in_out[1] = dup(STDOUT_FILENO);
	fdp->paths = init_path(fdp, cmnd_list, _envp, 0);
	fdp->pid = malloc (sizeof(int) * fdp->cmnd_cnt);
	if (!fdp->pid || !fdp->paths)
		return (ERROR);
	return (SUCCESS);
}

int	dup_and_close(int fd_to, int fd_from)
{
	if (dup2(fd_to, fd_from) == -1 || close(fd_to) == -1)
		return (ERROR);
	return (SUCCESS);
}

void	ft_free_array(char **arr)
{
	int	i;

	if (arr == NULL)
		return ;
	i = 0;
	while (arr[i] != NULL)
		free(arr[i++]);
	free(arr);
}

void	free_fdp(t_fdp *fdp)
{
	free(fdp->pid);
	ft_free_array(fdp->paths);
}
