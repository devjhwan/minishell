/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 01:18:14 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/10 02:09:21 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "list.h"

typedef struct s_command_info
{
	t_list	*redirection;
	t_list	*command;
}	t_command;

typedef struct s_redirection
{
	char	type;
	char	*file;
}	t_redirection;

t_command	*create_command(void);
void		free_command(void *command);
void		print_command_list(t_list *command_list);

#endif
