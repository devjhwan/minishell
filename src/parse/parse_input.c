/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:11:11 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/14 01:06:27 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_cmnd	*parse_input(char *line, t_minishell *shell)
{
	t_list	*lexer_list;
	t_list	*parser_list;
	t_list	*expander_list;
	t_cmnd	*cmnd_list;

	if (line == NULL)
		return (NULL);
	lexer_list = lexer(line);
	if (lexer_list == NULL)
		return (NULL);
	parser_list = parser(lexer_list, shell);
	if (parser_list == NULL)
		return (NULL);
	expander_list = expander(parser_list, shell);
	if (expander_list == NULL)
		return (NULL);
	cmnd_list = command_builder(expander_list);
	if (cmnd_list == NULL)
		return (NULL);
	return (cmnd_list);
}
