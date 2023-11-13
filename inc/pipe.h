/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinel <jmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:05:41 by jmarinel          #+#    #+#             */
/*   Updated: 2023/11/13 14:46:20 by jmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_H
# define PIPE_H

# include <stdio.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <fcntl.h>
# include <string.h>
# include <unistd.h>
# include "libft.h"

# define ERR_ARG	1
# define ERR_MC		2
# define ERR_CNF	3
# define ERR_PERM	4
# define ERR_NFD	5
# define ERR_PERR	10
# define INF		0
# define OUTF		1

typedef enum s_redir_type
{
	NO_REDIR,
	IN,
	HERE_DOC,
	OUT,
	OUT_APPEND,
}	t_type;

typedef struct s_in_out
{
	t_type			type;
	char			*file;
	struct s_in_out	*next;
}					t_io;

typedef struct s_cmnd
{
	char			**args;
	t_io			*redir;
	struct s_cmnd	*prev;
	struct s_cmnd	*next;
}					t_cmnd;

typedef struct s_fdp
{
	int		fd_pipe[2];
	int		fd_file[2];
	t_io	*tmp_in;
	t_io	*tmp_out;
	int		*pid;
	char	*lim;
	int		i;
	int		cmnd_cnt;
	int		dup_stdin;
	int		dup_stdout;
}			t_fdp;


/*### NEW PIPE ###*/
int		here_doc(t_io *redir);
int		redirect(t_io *redir, t_fdp *fdp);
void	manage_files(t_fdp	*fdp);
void	get_redir(t_io *redir, t_fdp *fdp);
void	open_outfile(t_fdp *fdp);

int		init_data(t_fdp *fdp, t_cmnd *cmnd_list);
void	ft_free_array(char **arr, int i);


/*### OLD PIPEX ###*/
t_ruta	ft_routing(t_fdp fdp, int flag);
int		ft_error(int err, int ext, char *cmd);
char	**findpath(char **env);
size_t	ft_strlen(const char *str);
char	*setpath(char **path, const char *argv);
char	*ft_strjoin(char const *s1, char const *s2);
int		*check_files(char **argv, int argc, int hd, int *io);
int		child(char **envp, t_fdp *fdp, char *cmd);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_close_fds(t_fdp *fdp);
t_fdp	ft_init_fdp(t_fdp *fdp, int argc, char **argv);
char	**ft_init_cmd(t_fdp *fdp, char **argv, char **envp, int i);
int		ft_mult_pipes(t_fdp *fdp, char **cmds, char **envp, int ret);
int		ft_dup_close(int fd_to, int fd_from);
void	ft_init_argv(char **argv, t_fdp *fdp);
void	ft_freep(char **willy);

#endif