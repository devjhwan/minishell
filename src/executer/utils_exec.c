/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinel <jmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:22:39 by jmarinel          #+#    #+#             */
/*   Updated: 2023/11/22 19:28:32 by jmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

int	check_builtin(t_cmnd *cmnd_list)
{
	if (cmnd_list && cmnd_list->args && cmnd_list->args[0])
	{
		if (ft_strcmp_case(cmnd_list->args[0], "echo", 1) == 0)
			return (1);
		else if (ft_strcmp_case(cmnd_list->args[0], "cd", 1) == 0)
			return (1);
		else if (ft_strcmp_case(cmnd_list->args[0], "pwd", 1) == 0)
			return (1);
		else if (ft_strcmp_case(cmnd_list->args[0], "env", 1) == 0)
			return (1);
		else if (ft_strcmp_case(cmnd_list->args[0], "export", 0) == 0)
			return (1);
		else if (ft_strcmp_case(cmnd_list->args[0], "unset", 0) == 0)
			return (1);
		else if (ft_strcmp_case(cmnd_list->args[0], "exit", 0) == 0)
			return (1);
	}
	return (0);
}

void	exec_builtin(t_minishell *shell, t_cmnd *cmnd_list)
{
	if (cmnd_list && cmnd_list->args && cmnd_list->args[0])
	{
		if (ft_strcmp_case(cmnd_list->args[0], "env", 1) == 0)
			env(shell);
/* 		else if (ft_strcmp_case(cmnd_list->args[0], "cd", 1) == 0)
			return (cd(shell));
		else if (ft_strcmp_case(cmnd_list->args[0], "pwd", 1) == 0)
			return (pwd(shell));
		else if (ft_strcmp_case(cmnd_list->args[0], "echo", 1) == 0)
			return (echo(shell));
		else if (ft_strcmp_case(cmnd_list->args[0], "export", 0) == 0)
			return (export(shell));
		else if (ft_strcmp_case(cmnd_list->args[0], "unset", 0) == 0)
			return (unset(shell));
		else if (ft_strcmp_case(cmnd_list->args[0], "exit", 0) == 0)
			return (exit(shell)); */
	}
}

void	restore_io(t_fdp *fdp)
{
	dup2(fdp->dup_stdin, STDIN_FILENO);
	dup2(fdp->dup_stdout, STDOUT_FILENO);
}

void	close_fds(t_fdp *fdp)
{
	if (fdp->fd_file[0])
		close (fdp->fd_file[0]);
	if (fdp->fd_file[1])
		close (fdp->fd_file[1]);
	if (fdp->fd_pipe[0])
		close (fdp->fd_pipe[0]);
	if (fdp->fd_pipe[1])
		close (fdp->fd_pipe[1]);
	/* if (fdp->pid)
		free(fdp->pid); */
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
