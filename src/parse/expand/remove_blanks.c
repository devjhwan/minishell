/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_blanks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:02:59 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/14 18:08:24 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

t_list	*remove_blanks(t_list *parse_list)
{
	t_list		*new_parse_list;
	t_list_node	*cur_node;
	t_token		*cur_token;
	t_token		*new_token;

	new_parse_list = list_init();
	if (new_parse_list == NULL)
		return (list_clear(parse_list, free_token), NULL);
	cur_node = parse_list->header;
	while (cur_node != NULL)
	{
		cur_token = (t_token *)cur_node->content;
		if (cur_token->type != BK)
		{
			new_token = create_token(cur_token->type, \
						(void *)ft_strdup((char *)cur_token->content));
			if (new_token == NULL)
				return (list_clear(new_parse_list, free_token), \
						list_clear(parse_list, free_token), NULL);
			list_append(new_parse_list, (void *)new_token);
		}
		cur_node = cur_node->next;
	}
	return (list_clear(parse_list, free_token), new_parse_list);
}
