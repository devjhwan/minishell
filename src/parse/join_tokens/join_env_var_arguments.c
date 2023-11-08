/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_env_var_arguments.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 03:08:57 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/08 03:20:59 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

static t_token	*merge_env_var_argument(t_list_node **node)
{
	t_token	*new_token;
	t_token	*cur_token;
	char	*new_content;

	cur_token = (t_token *)(*node)->content;
	new_content = ft_strdup((char *)cur_token->content);
	if (new_content == NULL)
		return (NULL);
	if ((*node)->next != NULL)
		cur_token = (t_token *)(*node)->next->content;
	if (cur_token->type == ARG)
	{
		new_content = join_content(new_content, (char *)cur_token->content);
		if (new_content == NULL)
			return (NULL);
		*node = (*node)->next;
	}
	new_token = create_token(ARG, new_content);
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
		if (cur_token->type == E_VAR)
			new_token = merge_env_var_argument(&cur_node);
		else
			new_token = create_token(cur_token->type, \
									(void *)ft_strdup(cur_token->content));
		if (new_token == NULL)
			return (NULL);
		if (list_append(new_token_list, new_token) == NULL)
			return (free_token((void *)new_token), NULL);
		cur_node = cur_node->next;
	}
	return (new_token_list);
}

t_list	*join_env_var_arguments(t_list *token_list)
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
