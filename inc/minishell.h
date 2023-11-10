/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 01:18:14 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/10 04:05:26 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "list.h"
# include <stdlib.h>

typedef struct s_command_info
{
	t_list	*redirection;
	t_list	*command;
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

t_command		*create_command(void);
void			free_command(void *command);
void			print_command_list(t_list *command_list);

t_redirection	*get_redirection(t_command *command);
void			free_redirection(t_redirection *redirection);
char			**get_command_arguments(t_command *command);
void			free_command_arguments(char **cmd_arguments);

#endif
