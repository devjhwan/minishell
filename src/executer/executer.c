/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinel <jmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:20:26 by jmarinel          #+#    #+#             */
/*   Updated: 2023/11/23 16:36:08 by jmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

/* 		if (fdp.cmnd_cnt == 1 && check_builtin(shell->cmnd_list))
			manage_builtins(shell); */

int	executer(t_cmnd *cmnd_list, char **_envp, int *exit_code, t_minishell *shell)
{
	t_fdp	fdp;

	if (cmnd_list != NULL)
	{
		if (init_data(&fdp, cmnd_list, _envp))
			return (1);
		if (redirect(cmnd_list->redir, &fdp, cmnd_list))
            return (1);
		if (fdp.cmnd_cnt == 1 && check_builtin(cmnd_list))
			return (only_cmnd(&fdp, cmnd_list, shell));
		while (cmnd_list)
		{
			if (exec_cmnds(shell, &fdp))
				return (1);
			cmnd_list = cmnd_list->next;
			fdp.i++;
		}
	}
	wait_childs(&fdp, exit_code);
	//free_fdp(&fdp);
	return (0);
}

int		exec_cmnds(t_minishell *shell, t_fdp *fdp)
{
	fdp->pid[fdp->i] = fork();
	if (fdp->pid[fdp->i] == -1)
		return (1);
	else if (fdp->pid[fdp->i] == 0)
		exec_childs(fdp, shell, shell->cmnd_list);
	//dup2 (fdp->pipe[fdp->i][RD], STDOUT);
    //close_fds(fdp);
    return (0);
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
	free(fdp->pid);
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


/* static void testprinter(t_minishell *shell, t_fdp *fdp)
{
	static int i = -1;

	printf("cmnd list size = %d\n", fdp->cmnd_cnt);
	while (shell->cmnd_list->args[++i])
		printf("arg %d  = %s\n", i, shell->cmnd_list->args[i]);
    printf("redir type = %i\n", shell->cmnd_list->redir->type);
	printf("redir adress = %p\n", shell->cmnd_list->redir);
	printf("redir adress = %s\n", shell->cmnd_list->redir->file);
	printf("redir adress = %s\n", shell->cmnd_list->args[0]);
	printf("pipes fds:\nRead end: %d\n Write end: %d\n", fdp->fd_pipe[0], fdp->fd_pipe[1]);
	printf("cmnds en [i] es %s\n", cmnds[fdp->i]);
	fprintf(stderr, "\nentro en middle\n");
} */

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