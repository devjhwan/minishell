/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_arguments.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:05:03 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/07 21:41:11 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

static t_token	*copy_token(char type, char *content)
{
	t_token	*new_token;
	char	*str;

	str = ft_strdup(content);
	if (str == NULL)
		return (NULL);
	new_token = create_token(type, str);
	if (new_token == NULL)
		return (free(str), NULL);
	return (new_token);
}

static char	*join_content(char *new_content, char *cur_content)
{
	char	*str;

	str = ft_strjoin(new_content, cur_content);
	free(new_content);
	if (str == NULL)
		return (NULL);
	return (str);
}

static t_token	*join_quote_argument(t_list_node **node, char quote_type)
{
	t_token	*new_token;
	t_token	*cur_token;
	char	*new_content;

	new_content = ft_strdup("");
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
	new_token = create_token(ARG, new_content);
	if (new_token == NULL)
		return (free(new_content), NULL);
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
		if (cur_token->type == SQ)
			new_token = join_quote_argument(&cur_node, SQ);
		else if (cur_token->type == DQ)
			new_token = join_quote_argument(&cur_node, DQ);
		else if (cur_token->type == WD)
			new_token = copy_token(ARG, (void *)cur_token->content);
		else
			new_token = copy_token(cur_token->type, \
									(void *)cur_token->content);
		if (new_token == NULL)
			return (NULL);
		if (list_append(new_token_list, new_token) == NULL)
			return (free_token((void *)new_token), NULL);
		cur_node = cur_node->next;
	}
	return (new_token_list);
}

t_list	*join_arguments(t_list *token_list)
{
	t_list	*new_token_list;

	new_token_list = list_init();
	if (new_token_list == NULL)
		return (list_clear(token_list, free_token), NULL);
	if (token_list->size == 0)
		return (list_clear(token_list, free_token), new_token_list);
	if (loop_on_token_list(token_list, new_token_list) == NULL)
		return (list_clear(new_token_list, free_token), \
				list_clear(token_list, free_token), NULL);
	return (list_clear(token_list, free_token), new_token_list);
}
