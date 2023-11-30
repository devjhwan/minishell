/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_exec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:29:24 by jmarinel          #+#    #+#             */
/*   Updated: 2023/11/30 12:13:24 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

void	printfds(void)
{
/* 	int max_fd = 256; // You can adjust this based on your needs
    fprintf(stderr, "\nOpen File Descriptors:\n");

    for (int fd = 0; fd < max_fd; ++fd) {
        int flags = fcntl(fd, F_GETFD);
        if (flags != -1) {
            fprintf(stderr, "File Descriptor %d is open.\n", fd);
        }
    } */
}

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
	if (init_pipes(fdp))
		return (1);
	fdp->std_in_out[READ] = dup(STDIN_FILENO);
	fdp->std_in_out[WRTE] = dup(STDOUT_FILENO);
	fdp->paths = init_path(fdp, cmnd_list, _envp, 0);
	fdp->pid = malloc (sizeof(int) * fdp->cmnd_cnt);
	if (!fdp->pid || !fdp->paths)
	{
		return (1);
		free_fdp(fdp);
	}
	return (0);
}

//fprintf(stderr, "hago pipes\n");

int	init_pipes(t_fdp	*fdp)
{
	static int	i = 0;

	if (fdp->cmnd_cnt > 1)
	{
		fdp->pipes = malloc(sizeof(t_pipe) * (fdp->cmnd_cnt - 1));
		if (!fdp->pipes)
		{
			perror("malloc");
			return (1);
		}
		while (fdp->cmnd_cnt - 1 > i)
		{
			if (pipe(fdp->pipes[i].fd) == -1)
			{
				perror("pipe");
				return (1);
			}
			i++;
		}		
	}
	return (0);
}

int	dup_and_close(int fd_to, int fd_from)
{
	if (dup2(fd_to, fd_from) == -1)
		return (1);
	if (close(fd_to) == -1)
		return (1);
	return (0);
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
	if (fdp->pipes)
		free(fdp->pipes);
	if (fdp->pid)
		free(fdp->pid);
	if (fdp->paths)
		ft_free_array(fdp->paths);
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
