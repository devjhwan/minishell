/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_empty_nodes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 02:41:07 by junghwle          #+#    #+#             */
/*   Updated: 2023/12/14 10:43:51 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

static void	delete_node(t_list *parse_list, t_list_node *cur_node, \
					t_list_node *prev_node)
{
	if (prev_node == NULL)
		parse_list->header = cur_node->next;
	else
		prev_node->next = cur_node->next;
	free(((t_token *)cur_node->content)->content);
	free((t_token *)cur_node->content);
}

t_list	*clear_empty_nodes(t_list *parse_list)
{
	t_list_node	*cur_node;
	t_list_node	*prev_node;
	t_token		*cur_token;
	char		*argument;

	cur_node = parse_list->header;
	prev_node = NULL;
	while (cur_node != NULL)
	{
		cur_token = (t_token *)cur_node->content;
		argument = (char *)cur_token->content;
		if (argument[0] == '\0')
			delete_node(parse_list, cur_node, prev_node);
		prev_node = cur_node;
		cur_node = cur_node->next;
	}
	return (parse_list);
}
