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

int	executer(t_minishell *shell)
{
	t_fdp	fdp;

	if (shell->cmnd_list != NULL)
	{
		ft_bzero((void *)&fdp, sizeof(t_fdp));
		init_data(&fdp, shell->cmnd_list, shell->_envp);
		mult_pipes(&fdp, shell, fdp.paths);
	}
	restore_io(&fdp);
	fdp.i = 0;
	/* while (fdp.i < fdp.cmnd_cnt)
	{
		waitpid(fdp.pid[fdp.i], &fdp.stat, 0);
		fdp.i++;
	} */
	ft_free_array(fdp.paths, ft_arraylen(fdp.paths));
	return (shell->exit_code = WEXITSTATUS(fdp.stat), 0);
}

void	mult_pipes(t_fdp *fdp, t_minishell *shell, char **cmnds)
{
	t_cmnd	*cmnd_list;

	cmnd_list = shell->cmnd_list;
	while (cmnd_list)
	{
		redirect(cmnd_list->redir, fdp, shell);
		if (fdp->i == 0)
		{
			first_cmnd(fdp, cmnd_list, shell, cmnds[fdp->i]);
		}
		else if (fdp->cmnd_cnt >= 3 && fdp->i + 1 != fdp->cmnd_cnt)
		{
			middle_cmnd(fdp, cmnd_list, shell, cmnds[fdp->i]);
		}
		else if (fdp->cmnd_cnt > 1)
		{
			final_cmnd(fdp, cmnd_list, shell, cmnds[fdp->i]);
		}
		cmnd_list = cmnd_list->next;
		fdp->i++;
	}
}

void	child(char **envp, t_fdp *fdp, char **args, char *cmnd)
{
	close_fds(fdp);
	fprintf(stderr, "command is %s\n", cmnd);
	if (execve (cmnd, args, envp) == -1)
		ft_error(0, 0, NULL);
}

void	test_child(char **envp, t_fdp *fdp, char **args, char *cmnd)
{
	close_fds(fdp);
	if (execve (cmnd, args, envp) == -1)
		ft_error(0, 0, NULL);
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