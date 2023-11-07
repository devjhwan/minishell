/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:17:22 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/07 19:22:32 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "list.h"
# include "tree.h"
# include <stdlib.h>

typedef struct s_token
{
	char	*content;
}	t_token;

typedef struct s_command
{
	void	*content;
}	t_command;

t_token		*create_token(char *content);
t_command	*create_command(void *content);

void		free_token(void *token);
void		free_command(void *command);

t_list		*parse_input(char *line);
t_list		*lexer(char *line);
t_tree		*parser(t_list	*token_list);
t_tree		*expander(t_tree *parse_tree);
t_list		*executor(t_tree *expander_tree);

/*debug*/
void		print_lexer(t_list *token_list);

#endif