// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   pipe.c                                             :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: jmarinel <jmarinel@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/06/27 16:20:26 by jmarinel          #+#    #+#             */
// /*   Updated: 2023/11/14 14:07:37 by jmarinel         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "pipe.h"

// int	executor(t_minishell *shell)
// {
// 	t_fdp	fdp;

// 	if (shell->cmnd_list != NULL && shell->cmnd_list->next == NULL)
// 	{
// 		ft_bzero((void *)&fdp, sizeof(t_fdp));
// 		init_data(&fdp, shell->cmnd_list);
// 		// check_builtin
// 		return (0);
// 	}
// 	else
// 	{
// 		ft_bzero((void *)&fdp, sizeof(t_fdp));
// 		init_data(&fdp, shell->cmnd_list);
// 		ft_mult_pipes();
// 	}
// 	return (0);
// }

// void	mult_pipes(t_fdp *fdp, t_minishell *shell)
// {
// 	t_cmnd	*cmnd_list;

// 	cmnd_list = shell->cmnd_list;
// 	while (cmnd_list)
// 	{
// 		redirect(cmnd_list->redir, fdp, shell);
// 		if (!fdp->i)
// 			first_cmnd(fdp, cmnd_list, shell);
// 		else if (fdp->cmnd_cnt >= 3)
// 			middle_cmnd(fdp, cmnd_list, shell);
// 		else
// 			final_cmnd(fdp, cmnd_list, shell);
// 		cmnd_list = cmnd_list->next;
// 		fdp->i++;
// 	}
// }

// int	child(char **envp, t_fdp *fdp, char **args)
// {
// 	close_fds(fdp);
// 	execve (args[0], &args[1], envp);
// 	exit (1);
// 	return (0);
// }
// /* char	**ft_init_cmd(t_fdp *fdp, char **argv, char **envp, int i)
// {
// 	char	**cmds;
// 	char	**arg;
// 	char	**path;

// 	path = findpath(envp);
// 	cmds = malloc(sizeof(char *) * (fdp->cnt + 1));
// 	if (!cmds)
// 		return (NULL);
// 	cmds[fdp->cnt] = NULL;
// 	ft_init_argv(argv, fdp);
// 	while (i < fdp->cnt)
// 	{
// 		arg = ft_split(fdp->argv[i], ' ');
// 		cmds[i] = setpath(path, arg[0]);
// 		if (!arg || !path)
// 			return (NULL);
// 		ft_freep(arg);
// 		i++;
// 	}
// 	ft_freep(path);
// 	return (cmds);
// } */

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