/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:17:22 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/14 18:42:55 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"
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

t_token			*create_token(char type, char *content);
void			free_token(void *token);

t_cmnd			*parse_input(char *line, t_minishell *shell);
t_list			*lexer(char *line);
t_list			*parser(t_list *token_list, t_minishell *shell);
t_list			*expander(t_list *parse_list, t_minishell *shell);
t_cmnd			*command_builder(t_list *expander_list);

char			*join_content(char *new_content, char *cur_content);
t_list			*join_tokens(t_list *token_list);
t_list			*join_arguments(t_list *token_list);
t_list			*join_env_var_arguments(t_list *token_list);
t_list			*join_redirections(t_list *token_list);

t_list			*check_token_error(t_list *token_list, t_minishell *shell);
int				check_redirection(t_list_node *cur_node, t_minishell *shell);
int				check_pipe(t_list *token_list, t_list_node *cur_node, \
														int *exit_code);

t_list			*expand_env_variables(t_list *parse_list, t_minishell *shell);
t_list			*remove_quotes(t_list *parse_list);
t_list			*merge_consecutive_arguments(t_list *parse_list);
t_list			*remove_blanks(t_list *parse_list);
char			*search_env_value(char *substr, char **envp, \
										t_minishell *shell);

void			free_redirection(t_io *redir);
void			free_arguments(char **args);
void			free_cmnd_list(t_cmnd **cmnd_list);

int				ismetacharacter(char ch);
char			*append_substr(char	*dest, char	*src, \
							unsigned int start, size_t len);
char			*replace_substr(char *str, char *substr, char *replace_str);
int				isquote(char ch);

/*debug*/
void			print_token_list(t_list *token_list);

#endif