/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_blank_from_env.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 02:41:07 by junghwle          #+#    #+#             */
/*   Updated: 2023/12/13 22:34:45 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

static int	split_argument(t_list_node *cur_node, t_minishell *shell, \
							char *arg)
{
	t_list		*lexer_list;
	t_list		*parser_list;
	t_token		*cur_token;
	t_list_node	*tmp_node;

	if (arg == NULL || arg[0] == '\0')
		return (0);
	lexer_list = lexer(arg);
	if (lexer_list == NULL)
		return (1);
	parser_list = parser(lexer_list, shell);
	if (parser_list == NULL)
		return (1);
	cur_token = (t_token *)cur_node->content;
	free(cur_token->content);
	cur_token->content = ((t_token *)parser_list->header->content)->content;
	cur_token->type = ((t_token *)parser_list->header->content)->type;
	tmp_node = parser_list->header;
	while (tmp_node->next != NULL)
		tmp_node = tmp_node->next;
	tmp_node->next = cur_node->next;
	cur_node->next = parser_list->header->next;
	parser_list->header->next = NULL;
	return (free(parser_list->header->content), free(parser_list->header), \
			free(parser_list), 0);
}

t_list	*split_blank_from_env(t_list *parse_list, t_minishell *shell)
{
	t_list_node	*cur_node;
	t_token		*cur_token;
	char		*argument;

	cur_node = parse_list->header;
	while (cur_node != NULL)
	{
		cur_token = (t_token *)cur_node->content;
		argument = (char *)cur_token->content;
		if (cur_token->type != PIPE)
			if (split_argument(cur_node, shell, argument) == 1)
				return (list_clear(parse_list, free_token), NULL);
		cur_node = cur_node->next;
	}
	return (parse_list);
}
