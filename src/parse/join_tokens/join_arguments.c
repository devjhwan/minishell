/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_arguments.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:05:03 by junghwle          #+#    #+#             */
/*   Updated: 2023/12/13 16:11:33 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

static char	*append_quote_to_argument(char *new_content, char quote_type)
{
	if (quote_type == SQ)
		new_content = join_content(new_content, "\'");
	else
		new_content = join_content(new_content, "\"");
	if (new_content == NULL)
		return (NULL);
	return (new_content);
}

static t_token	*merge_quote_argument(t_list_node **node, char quote_type)
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
	while (*node != NULL && cur_token->type != quote_type)
	{
		new_content = join_content(new_content, (char *)cur_token->content);
		if (new_content == NULL)
			return (NULL);
		*node = (*node)->next;
		if (*node != NULL)
			cur_token = (t_token *)(*node)->content;
	}
	new_content = append_quote_to_argument(new_content, quote_type);
	new_token = create_token(ARG, new_content);
	return (new_token);
}

static t_token	*get_merged_token(char token_type, t_list_node **cur_node, \
													char *cur_content)
{
	t_token	*new_token;

	if (token_type == SQ)
		new_token = merge_quote_argument(cur_node, SQ);
	else if (token_type == DQ)
		new_token = merge_quote_argument(cur_node, DQ);
	else if (token_type == WD)
		new_token = create_token(ARG, (void *)ft_strdup(cur_content));
	else
		new_token = create_token(token_type, (void *)ft_strdup(cur_content));
	return (new_token);
}

static t_list	*loop_on_token_list(t_list *token_list, t_list *new_token_list)
{
	t_list_node	*cur_node;
	t_token		*cur_token;
	t_token		*new_token;
	
	cur_node = token_list->header;
	while (cur_node != NULL)
	{
		cur_token = (t_token *)cur_node->content;
		new_token = get_merged_token(cur_token->type, &cur_node, \
										(char *)cur_token->content);
		if (new_token == NULL)
			return (NULL);
		if (list_append(new_token_list, new_token) == NULL)
			return (free_token((void *)new_token), NULL);
		if (cur_node != NULL)
			cur_node = cur_node->next;
	}
	return (new_token_list);
}

t_list	*join_arguments(t_list *token_list)
{
	t_list	*new_token_list;

	if (token_list->size == 0)
		return (token_list);
	new_token_list = list_init();
	if (new_token_list == NULL)
		return (list_clear(token_list, free_token), NULL);
	if (loop_on_token_list(token_list, new_token_list) == NULL)
		return (list_clear(new_token_list, free_token), \
				list_clear(token_list, free_token), NULL);
	return (list_clear(token_list, free_token), new_token_list);
}
