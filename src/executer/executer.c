/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinel <jmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:20:26 by jmarinel          #+#    #+#             */
/*   Updated: 2023/11/14 20:05:35 by jmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

int	executer(t_minishell *shell)
{
	t_fdp	fdp;
	char	**cmnds;

	cmnds = NULL;
	if (shell->cmnd_list != NULL)
	{
		ft_bzero((void *)&fdp, sizeof(t_fdp));
		init_data(&fdp, shell->cmnd_list);
		cmnds = ft_init_cmd(&fdp, shell->cmnd_list->args, shell->_envp, 0);
/* 		if (fdp.cmnd_cnt == 1 && check_builtin(shell->cmnd_list))
			manage_builtins(shell); */
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
		if (fdp->i == 0)
		{
			printf("\nentro en first\n");
			first_cmnd(fdp, cmnd_list, shell, cmnds[fdp->i]);
		}
		else if (fdp->i + 1 == fdp->cmnd_cnt)
		{
			fprintf(stderr, "\nentro en final\n");
			final_cmnd(fdp, cmnd_list, shell, cmnds[fdp->i]);
		}
		else if (fdp->cmnd_cnt >= 3)
		{
			fprintf(stderr, "\nentro en middle\n");
			middle_cmnd(fdp, cmnd_list, shell, cmnds[fdp->i]);
		}
		printf("\nllego a ciclar\n");
		cmnd_list = cmnd_list->next;
		fdp->i++;
	}
}

void	child(char **envp, t_fdp *fdp, char **args, char *cmnd)
{
	close_fds(fdp);
	write(2, "hi\n", 3);
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
} */


/* #include <fcntl.h>
static void printfds(void)
{

    int max_fd = 256;  // You can adjust this based on your needs

    printf("Open File Descriptors:\n");

    for (int fd = 0; fd < max_fd; ++fd) {
        int flags = fcntl(fd, F_GETFD);
        if (flags != -1) {
            printf("File Descriptor %d is open.\n", fd);
        }
    }
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