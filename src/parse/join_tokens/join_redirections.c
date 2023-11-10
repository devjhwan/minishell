/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_redirections.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 01:31:16 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/10 04:10:16 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

static char	*get_merged_content(char token_type, char *new_content, \
													char *cur_content)
{
	if (token_type == BK)
		return (new_content);
	if ((token_type == ARG))
	{
		new_content = join_content(new_content, " ");
		if (new_content == NULL)
			return (NULL);
		new_content = join_content(new_content, cur_content);
	}
	return (new_content);
}

static t_token	*merge_redirection(t_list_node **node)
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
	while (*node != NULL && (cur_token->type == BK || cur_token->type == ARG))
	{
		new_content = get_merged_content(cur_token->type, new_content, \
											(char *)cur_token->content);
		if (new_content == NULL)
			return (NULL);
		if (cur_token->type == ARG)
			break ;
		*node = (*node)->next;
		if (*node != NULL)
			cur_token = (t_token *)(*node)->content;
	}
	new_token = create_token(RD, new_content);
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
		if (cur_token->type == RD)
			new_token = merge_redirection(&cur_node);
		else
			new_token = create_token(cur_token->type, \
							(void *)ft_strdup((char *)cur_token->content));
		if (new_token == NULL)
			return (NULL);
		if (list_append(new_token_list, new_token) == NULL)
			return (free_token((void *)new_token), NULL);
		if (cur_token->type == RD && cur_node != NULL && \
			((t_token *)cur_node->content)->type == PIPE)
			continue ;
		if (cur_node != NULL && ((t_token *)cur_node->content)->type != RD)
			cur_node = cur_node->next;
	}
	return (new_token_list);
}

t_list	*join_redirections(t_list *token_list)
{
	t_list		*new_token_list;

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
