/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:20:26 by jmarinel          #+#    #+#             */
/*   Updated: 2023/11/30 15:50:54 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

int	executer(t_cmnd *cmnd_list, char **_envp, int *exit_code, t_minishell *shell)
{
	t_fdp	fdp;

	if (cmnd_list != NULL)
	{
		if (init_data(&fdp, cmnd_list, _envp))
			return (1);
		if (cmnd_list->next == NULL && check_builtin(cmnd_list))
			return (only_cmnd(&fdp, cmnd_list, shell));
		while (cmnd_list)
		{
			if (redirect(cmnd_list->redir, &fdp, cmnd_list))
				return (1);
			pipe(fdp.pipe);
			if (do_fork(shell, &fdp, cmnd_list))
				return (1);
			dup_and_close(fdp.pipe[0], STDIN_FILENO);
			close (fdp.pipe[1]);
			cmnd_list = cmnd_list->next;
			fdp.child_id++;
		}
	}
	wait_childs(&fdp, exit_code);
	close_fds(&fdp);
	free_fdp(&fdp);
	return (0);
}

int		do_fork(t_minishell *shell, t_fdp *fdp, t_cmnd *cmnd_list)
{
	fdp->pid[fdp->child_id] = fork();
	if (fdp->pid[fdp->child_id] == -1)
		return (1);
	else if (fdp->pid[fdp->child_id] == 0)
	{
		exec_childs(fdp, shell, cmnd_list);
		return (0);
	}
    return (0);
}

void	exec_childs(t_fdp *fdp, t_minishell *shell, t_cmnd *cmnds)
{
	if (fdp->tmp_in)
		set_redir_in(fdp);
	if (cmnds->next != NULL)
	{
		dup_and_close(fdp->pipe[1], STDOUT_FILENO);
		close(fdp->pipe[0]);
	}
	if (fdp->tmp_out)
		set_redir_out(fdp);
	if (check_builtin(cmnds))
	{
		exec_builtin(shell, cmnds);
		//restore_io(fdp); no hace falta?
	}
	else
		child(shell->_envp, fdp, cmnds->args, fdp->paths[fdp->child_id]);
}

void	child(char **envp, t_fdp *fdp, char **args, char *cmnd)
{
	(void)fdp;
	if (execve (cmnd, args, envp) == -1)
		ft_error(0, 0, NULL);
}

void	wait_childs(t_fdp *fdp, int *exit_code)
{
	int	i;
	int	status;

	i = 0;
	restore_io(fdp);
	while (i < fdp->cmnd_cnt)
	{
		waitpid(fdp->pid[i], &status, 0);
		i++;
	}
	if (WIFEXITED(status))
		*exit_code = (WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == SIGINT)
			*exit_code = 130;
		else if (WTERMSIG(status) == SIGQUIT)
		{
			*exit_code = 131;
			printf("Quit: 3\n");
		}
	}
}