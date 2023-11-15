/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinel <jmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:20:26 by jmarinel          #+#    #+#             */
/*   Updated: 2023/11/14 19:09:03 by jmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

int	executor(t_minishell *shell)
{
	t_fdp	fdp;
	char	**cmnds;

	cmnds = NULL;
	if (shell->cmnd_list != NULL && shell->cmnd_list->next == NULL)
	{
		ft_bzero((void *)&fdp, sizeof(t_fdp));
		init_data(&fdp, shell->cmnd_list);
		// check_builtin
		//else
		cmnds = ft_init_cmd(&fdp, shell->cmnd_list->args, shell->_envp, 0);
		child(shell->_envp, &fdp, shell->cmnd_list->args, cmnds[0]);
		return (0);
	}
	else
	{
		ft_bzero((void *)&fdp, sizeof(t_fdp));
		init_data(&fdp, shell->cmnd_list);
		cmnds = ft_init_cmd(&fdp, shell->cmnd_list->args, shell->_envp, 0);
		mult_pipes(&fdp, shell, cmnds);
	}
	restore_io(&fdp);
	ft_free_array(cmnds, ft_arraylen(cmnds));
	return (0);
}

void	mult_pipes(t_fdp *fdp, t_minishell *shell, char **cmnds)
{
	t_cmnd	*cmnd_list;

	cmnd_list = shell->cmnd_list;
	while (cmnd_list)
	{
		redirect(cmnd_list->redir, fdp, shell);
		if (!fdp->i)
			first_cmnd(fdp, cmnd_list, shell, cmnds[fdp->i]);
		else if (fdp->cmnd_cnt >= 3)
			middle_cmnd(fdp, cmnd_list, shell, cmnds[fdp->i]);
		else
			final_cmnd(fdp, cmnd_list, shell, cmnds[fdp->i]);
		cmnd_list = cmnd_list->next;
		fdp->i++;
	}
}

int	child(char **envp, t_fdp *fdp, char **args, char *cmnd)
{
	close_fds(fdp);
	execve (cmnd, args, envp);
	exit (1);
	return (0);
}


// /*while (cmds[i])
// 	{
// 		si no es el primero, queremos leer del read end de la pipe
// 		dup2(pipe[0], STDIN_FILENO)
// 		si no es here_doc y es el primero, queremos leer del fd del INF
// 		dup2(io[0], STDIN)
// 		si no es el ultimo, queremos escribir a la pipe
// 		dup2(pipe[1], STDOUT)
// 		si es el ultimo, queremos escribir al OUTF
// 		dup2(io[1], STDOUT)
// 	}
// */
// /*printf(" fd pipe [0] es %d\n fd pipe [1] es %d\n fd infile es %d\n 
// fd outfile es %d\n", fd[0],fd[1], io[0], io[1]);*/
// /* 
// if (fdp->i > 0)
// 			ret = ft_dup_close(fdp->fd_pipe[0], STDIN_FILENO);
// 		else
// 			ret = ft_dup_close(fdp->fd_file[0], STDIN_FILENO);
// 		if (pipe(fdp->fd_pipe) == -1)
// 			return (ft_error(ERR_PERR, 1, NULL));
// 		if (fdp->i + 1 != fdp->cmnd_cnt)
// 			ret = ft_dup_close(fdp->fd_pipe[1], STDOUT_FILENO);
// 		else
// 			ret = ft_dup_close(fdp->fd_file[1], STDOUT_FILENO);
// 		fdp->pid[fdp->i] = fork();
// 		if (fdp->pid[fdp->i] == 0)
// 			child(envp, fdp, cmnd_list->args); */