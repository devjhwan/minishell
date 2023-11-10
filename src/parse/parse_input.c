/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:11:11 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/10 00:55:09 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_list	*parse_input(char *line, char **envp, int *exit_code)
{
	t_list	*lexer_list;
	t_list	*parser_list;
	t_list	*expander_list;
	t_list	*executor_list;

	if (line == NULL)
		return (NULL);
	lexer_list = lexer(line);
	if (lexer_list == NULL)
		return (NULL);
	parser_list = parser(lexer_list, envp, exit_code);
	if (parser_list == NULL)
		return (NULL);
	expander_list = expander(parser_list, envp, *exit_code);
	if (expander_list == NULL)
		return (NULL);
	print_token_list(expander_list);
	executor_list = executor(expander_list);
	if (executor_list == NULL)
		return (NULL);
	return (executor_list);
}
