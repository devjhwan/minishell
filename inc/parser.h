/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:17:22 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/06 22:58:05 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdlib.h>

typedef struct s_token
{
	void	*content;
}	t_token;

typedef struct s_tree
{
	void	*content;
}	t_tree;

typedef struct s_command
{
	void	*content;
}	t_command;

t_token		*create_token(void *content);
t_command	*create_command(void *content);

void		free_token(void *token);
void		free_command(void *command);

#endif