/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:05:41 by jmarinel          #+#    #+#             */
/*   Updated: 2023/11/30 16:06:20 by junghwle         ###   ########.fr       */
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

typedef struct s_fdp
{
	int		pipe[2];
	t_io	*tmp_in;
	t_io	*tmp_out;
	int		fd_file[2];
	int		std_in_out[2];
	int		*pid;
	char	**paths;
	int		child_id;
	int		cmnd_cnt;
}			t_fdp;

/*### NEW PIPE ###*/
void	child(char **envp, t_fdp *fdp, char **args, char *cmnd);
int		check_builtin(t_cmnd *cmnd_list);
void	close_fds(t_fdp *fdp);
int		dup_and_close(int fd_to, int fd_from);
int		executer(t_cmnd *cmnd_list, char **_envp, int *exit_code, t_minishell *shell);
int		do_fork(t_minishell *shell, t_fdp *fdp, t_cmnd *cmnd_list);
void	exec_childs(t_fdp *fdp, t_minishell *shell, t_cmnd *cmnds);
int		exec_builtin(t_minishell *shell, t_cmnd *cmnd_list);
char	**findpath(char **env);
void	free_fdp(t_fdp *fdp);
void	ft_free_array(char **arr);
void	get_redir(t_io *redir, t_fdp *fdp, char **args);
t_io	*here_doc(t_io *redir, char *limiter);
int		init_data(t_fdp *fdp, t_cmnd *cmnd_list, char **_envp);
char	**init_path(t_fdp *fdp, t_cmnd *list, char **envp, int i);
int		manage_files(t_fdp	*fdp);
void	open_outfile(t_fdp *fdp);
int		redirect(t_io *redir, t_fdp *fdp, t_cmnd *cmnd_list);
void	restore_io(t_fdp *fdp);
int		set_redir_in(t_fdp	*fdp);
int		set_redir_out(t_fdp	*fdp);
void	wait_childs(t_fdp *fdp, int *exit_code);


int		only_cmnd(t_fdp *fdp, t_cmnd *list, t_minishell *shell);

/*### OLD PIPEX ###*/
int		ft_error(int err, int ext, char *cmd);
size_t	ft_strlen(const char *str);
char	*setpath(char **path, const char *argv);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif