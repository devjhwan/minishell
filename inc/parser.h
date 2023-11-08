/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:17:22 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/08 03:12:11 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "list.h"
# include "tree.h"
# include <stdlib.h>

/*TOKEN TYPES*/
# define UNKNOWN 0
# define RD 1
# define PIPE 2
# define PRTS 3
# define E_VAR 4
# define SQ 5
# define DQ 6
# define BK 7
# define WD 8
# define ARG 9

typedef struct s_token
{
	char	type;
	char	*content;
}	t_token;

typedef struct s_command
{
	void	*content;
}	t_command;

t_token		*create_token(char type, char *content);
t_command	*create_command(void *content);

void		free_token(void *token);
void		free_command(void *command);

t_list		*parse_input(char *line);
t_list		*lexer(char *line);
t_tree		*parser(t_list *token_list);
t_tree		*expander(t_tree *parse_tree);
t_list		*executor(t_tree *expander_tree);

int			ismetacharacter(char ch);
char		*join_content(char *new_content, char *cur_content);
t_list		*join_tokens(t_list *token_list);
t_list		*join_arguments(t_list *token_list);
t_list		*join_env_var_arguments(t_list *token_list);
t_list		*join_redirections(t_list *token_list);

/*debug*/
void		print_lexer(t_list *token_list);

#endif