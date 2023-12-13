/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_consecutive_arguments.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:49:20 by junghwle          #+#    #+#             */
/*   Updated: 2023/12/13 16:18:59 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

static t_token	*merge_arguments(t_list_node **node, char type)
{
	t_token	*new_token;
	t_token	*cur_token;
	char	*new_content;

	cur_token = (t_token *)(*node)->content;
	new_content = ft_strdup((char *)cur_token->content);
	if (new_content == NULL)
		return (NULL);
	*node = (*node)->next;
	if (*node != NULL)
		cur_token = (t_token *)(*node)->content;
	while (*node != NULL && cur_token->type == ARG)
	{
		new_content = join_content(new_content, cur_token->content);
		if (new_content == NULL)
			return (NULL);
		*node = (*node)->next;
		if (*node != NULL)
			cur_token = (t_token *)(*node)->content;
		if (cur_token->type == ARG)
			break ;
	}
	new_token = create_token(type, new_content);
	return (new_token);
}

static t_list	*loop_on_parse_list(t_list *parse_list, t_list *new_parse_list)
{
	t_list_node	*cur_node;
	t_token		*cur_token;
	t_token		*new_token;
	
	cur_node = parse_list->header;
	while (cur_node != NULL)
	{
		cur_token = (t_token *)cur_node->content;
		if (cur_token->type == ARG || cur_token->type == RD)
			new_token = merge_arguments(&cur_node, cur_token->type);
		else
		{
			new_token = create_token(cur_token->type, \
							(void *)ft_strdup((char *)cur_token->content));
			cur_node = cur_node->next;
		}
		if (new_token == NULL)
			return (NULL);
		if (list_append(new_parse_list, new_token) == NULL)
			return (free_token((void *)new_token), NULL);
		if (cur_node != NULL && ((t_token *)cur_node->content)->type == BK)
			cur_node = cur_node->next;
	}
	return (new_parse_list);
}

t_list	*merge_consecutive_arguments(t_list *parse_list)
{
	t_list		*new_parse_list;

	if (parse_list->size == 0)
		return (parse_list);
	new_parse_list = list_init();
	if (new_parse_list == NULL)
		return (list_clear(parse_list, free_token), NULL);
	if (loop_on_parse_list(parse_list, new_parse_list) == NULL)
		return (list_clear(new_parse_list, free_token), \
				list_clear(parse_list, free_token), NULL);
	return (list_clear(parse_list, free_token), new_parse_list);
}
