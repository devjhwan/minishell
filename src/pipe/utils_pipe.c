/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinel <jmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:22:39 by jmarinel          #+#    #+#             */
/*   Updated: 2023/11/13 17:11:08 by jmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe.h"

char	*setpath(char **path, const char *argv)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	i = 0;
	while (path[i])
	{
		tmp2 = ft_strjoin(path[i], "/");
		if (!tmp2)
			return (NULL);
		tmp = ft_strjoin(tmp2, argv);
		if (!tmp)
			return (free(tmp2), NULL);
		free(tmp2);
		if (access(tmp, X_OK) == 0)
		{
			return (tmp);
		}
		i++;
		free (tmp);
	}
	return (NULL);
}

char	**findpath(char **env)
{
	int		i;
	char	**path;

	path = NULL;
	i = 0;
	while (env[i] && env[i][0] != '\0')
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			env[i] += 5;
			path = ft_split(env[i], ':');
			if (!path)
				return (NULL);
			return (path);
		}
		else
			i++;
	}
	return (NULL);
}

void	ft_close_fds(t_fdp *fdp)
{
	close (fdp->fd_file[0]);
	close (fdp->fd_file[1]);
	close (fdp->fd_pipe[0]);
	close (fdp->fd_pipe[1]);
	free(fdp->pid);
}

int	ft_error(int err, int ext, char *cmd)
{
	(void)cmd;
	if (err == ERR_ARG)
		fprintf(stderr, "bash: Invalid number of arguments\n");
	else if (err == ERR_MC)
		fprintf(stderr, "bash: error trying to allocate memory\n");
	else if (err == ERR_CNF)
		fprintf(stderr, "pipex: command not found\n");
	else if (err == ERR_NFD)
		fprintf(stderr, "pipex: No such file or directory\n");
	else if (err == ERR_PERM)
		fprintf(stderr, "pipex: permission denied\n");
	else if (err == ERR_PERR)
		perror("bash: ");
	return (ext);
}

/* 
int	*check_files(char **argv, int argc, int hd, int *io)
{
	io = malloc (sizeof(int) * 2);
	if (!io)
		io = NULL;
	if (hd)
		io[0] = here_doc(argv);
	else if (!hd)
	{
		if (access(argv[1], F_OK | R_OK) != 0)
			io[0] = -1;
		else
			io[0] = open(argv[1], O_RDONLY);
	}
	if (access(argv[argc - 1], F_OK) == 0)
	{
		if (access(argv[argc - 1], W_OK) != 0)
			io[1] = -1;
		else if (hd)
			io[1] = open(argv[argc - 1], O_WRONLY | O_APPEND);
		else
			io[1] = open(argv[argc - 1], O_WRONLY | O_TRUNC);
	}
	else
		io[1] = open(argv[argc - 1], O_RDWR | O_CREAT, 00644);
	return (io);
} */