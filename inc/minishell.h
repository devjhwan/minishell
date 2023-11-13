/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinel <jmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 01:18:14 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/13 16:38:14 by jmarinel         ###   ########.fr       */
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
	t_list	*command_list;
	t_cmnd	*cmnd_list;
	char	**_envp;
	char	**_export;
	char	*home;
	char	*pwd;
	char	*oldpwd;
	int		exit_code;
}	t_minishell;

typedef struct s_command_info
{
	t_list					*redirection;
	t_list					*command;
	struct s_command_info	*next;
}	t_command;

# define UNKNOWN 0
# define IN 1
# define OUT 2
# define DIN 3
# define DOUT 4

typedef struct s_redirection
{
	char	type;
	char	*file;
}	t_redirection;

t_minishell		*init_minishell(int argc, char **argv, char **envp, \
								t_minishell *shell);
void			free_minishell(t_minishell shell);

void			set_minishell_terminal(void);
void			rollback_terminal_setting(void);
void			set_default_minishell_signal(void);
void			set_execution_signal(void);

t_command		*create_command(void);
void			free_command(void *command);
void			print_command_list(t_list *command_list);

t_redirection	*get_redirection(t_command *command);
void			free_redirection(t_redirection *redirection);
char			**get_command_arguments(t_command *command);
void			free_command_arguments(char **cmd_arguments);

/*DEBUG*/
void			test_get_command(t_list *command_list);

#endif
