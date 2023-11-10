/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:17:22 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/10 01:26:04 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "list.h"
# include <stdlib.h>

/*TOKEN TYPES*/
# define UNKNOWN 0
# define RD 1
# define PIPE 2
# define E_VAR 3
# define SQ 4
# define DQ 5
# define BK 6
# define WD 7
# define ARG 8

typedef struct s_token
{
	char	type;
	char	*content;
}	t_token;

t_token		*create_token(char type, char *content);
void		free_token(void *token);

t_list		*parse_input(char *line, char **envp, int *exit_code);
t_list		*lexer(char *line);
t_list		*parser(t_list *token_list, char **envp, int *exit_code);
t_list		*expander(t_list *parse_list, char **envp, int exit_code);
t_list		*executor(t_list *expander_list);

char		*join_content(char *new_content, char *cur_content);
t_list		*join_tokens(t_list *token_list);
t_list		*join_arguments(t_list *token_list);
t_list		*join_env_var_arguments(t_list *token_list);
t_list		*join_redirections(t_list *token_list);

t_list		*check_token_error(t_list *token_list, char **envp, \
														int *exit_code);
int			check_redirection(t_list_node *cur_node, char **envp, \
														int *exit_code);
int			check_pipe(t_list *token_list, t_list_node *cur_node, \
													int *exit_code);

t_list		*expand_env_variables(t_list *parse_list, char **envp, \
									int exit_code);
t_list		*remove_quotes(t_list *parse_list);
char		*search_env_value(char *substr, char **envp, int exit_code);

int			ismetacharacter(char ch);
char		*append_substr(char	*dest, char	*src, \
							unsigned int start, size_t len);
char		*replace_substr(char *str, char *substr, char *replace_str);
int			isquote(char ch);

/*debug*/
void		print_token_list(t_list *token_list);

#endif