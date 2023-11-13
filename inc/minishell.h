/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 01:18:14 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/13 17:26:32 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "list.h"
# include <stdlib.h>

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
	struct s_cmnd	*next;
}					t_cmnd;

typedef struct s_minishell
{
	t_cmnd	*cmnd_list;
	char	**_envp;
	char	**_export;
	char	*home;
	char	*pwd;
	char	*oldpwd;
	int		exit_code;
}	t_minishell;

t_minishell		*init_minishell(int argc, char **argv, char **envp, \
								t_minishell *shell);
void			free_minishell(t_minishell shell);

void			set_minishell_terminal(void);
void			rollback_terminal_setting(void);
void			set_default_minishell_signal(void);
void			set_execution_signal(void);

void			print_command_list(t_list *command_list);

/*DEBUG*/
void			test_get_command(t_list *command_list);

#endif
