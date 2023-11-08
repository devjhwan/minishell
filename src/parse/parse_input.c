/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:11:11 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/08 02:01:52 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_list	*parse_input(char *line)
{
	t_list	*lexer_list;
	t_tree	*parser_tree;
	t_tree	*expander_tree;
	t_list	*executor_list;

	if (line == NULL)
		return (NULL);
	lexer_list = lexer(line);
	if (lexer_list == NULL)
		return (NULL);
	parser_tree = parser(lexer_list);
	if (parser_tree == NULL)
		return (NULL);
	expander_tree = expander(parser_tree);
	if (expander_tree == NULL)
		return (NULL);
	executor_list = executor(expander_tree);
	if (executor_list == NULL)
		return (NULL);
	return (executor_list);
}
