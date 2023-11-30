/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinel <jmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:05:41 by jmarinel          #+#    #+#             */
/*   Updated: 2023/11/23 13:33:01 by jmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTER_H
# define EXECUTER_H

# include <stdio.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <fcntl.h>
# include <string.h>
# include <unistd.h>
# include <readline/readline.h>
# include "libft.h"
# include "minishell.h"

# define ERR_ARG	1
# define ERR_MC		2
# define ERR_CNF	3
# define ERR_PERM	4
# define ERR_NFD	5
# define ERR_PERR	10
# define INF		0
# define OUTF		1
# define READ		0
# define WRTE		1

typedef struct s_pipe
{
	int			fd[2];
}				t_pipe;

typedef struct s_fdp
{
	t_pipe	*pipes;
	int		pipe[2];
	t_io	*tmp_in;
	t_io	*tmp_out;
	int		fd_file[2];
	int		std_in_out[2];
	int		*pid;
	char	*lim;
	char	**paths;
	int		i;
	int		cmnd_cnt;
	int		stat;
}			t_fdp;

/*### NEW PIPE ###*/
void	child(char **envp, t_fdp *fdp, char **args, char *cmnd);
int		check_builtin(t_cmnd *cmnd_list);
void	close_fds(t_fdp *fdp);
int		dup_and_close(int fd_to, int fd_from);
int		executer(t_cmnd *cmnd_list, char **_envp, int *exit_code, t_minishell *shell);
int		do_fork(t_minishell *shell, t_fdp *fdp, t_cmnd *cmnd_list);
void	exec_childs(t_fdp *fdp, t_minishell *shell, t_cmnd *cmnds);
void	exec_builtin(t_minishell *shell, t_cmnd *cmnd_list);
char	**findpath(char **env);
void	free_fdp(t_fdp *fdp);
void	ft_free_array(char **arr, int i);
void	get_redir(t_io *redir, t_fdp *fdp, char **args);
t_io	*here_doc(t_io *redir, char *limiter);
int		init_data(t_fdp *fdp, t_cmnd *cmnd_list, char **_envp);
int		init_pipes(t_fdp	*fdp);
char	**init_path(t_fdp *fdp, t_cmnd *list, char **envp, int i);
void	manage_files(t_fdp	*fdp);
void	open_outfile(t_fdp *fdp);
int		redirect(t_io *redir, t_fdp *fdp, t_cmnd *cmnd_list);
void	restore_io(t_fdp *fdp);
int		set_redir_in(t_fdp	*fdp);
int		set_redir_out(t_fdp	*fdp);
void	test_child(char **envp, t_fdp *fdp, char **args, char *cmnd);
void	wait_childs(t_fdp *fdp, int *exit_code);


int		only_cmnd(t_fdp *fdp, t_cmnd *list, t_minishell *shell);
int		first_cmnd(t_fdp *fdp, t_cmnd *list, t_minishell *shell, char **path);
int		middle_cmnd(t_fdp *fdp, t_cmnd *list, t_minishell *shell, char **path);
int		final_cmnd(t_fdp *fdp, t_cmnd *list, t_minishell *shell, char **path);


/*### HELPER FUNCTIONS ###*/
void	printfds(void);

/*### OLD PIPEX ###*/
int		ft_error(int err, int ext, char *cmd);
size_t	ft_strlen(const char *str);
char	*setpath(char **path, const char *argv);
char	*ft_strjoin(char const *s1, char const *s2);
int		*check_files(char **argv, int argc, int hd, int *io);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
t_fdp	ft_init_fdp(t_fdp *fdp, int argc, char **argv);
void	ft_init_argv(char **argv, t_fdp *fdp);
void	ft_freep(char **willy);

#endif