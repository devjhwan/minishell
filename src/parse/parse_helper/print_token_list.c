/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_token_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:21:12 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/08 17:28:14 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdio.h>

void	print_token_list(t_list *token_list)
{
	t_list_node	*node;
	t_token		*token;
	int			count;

	node = token_list->header;
	count = 1;
	while (node != NULL)
	{
		token = (t_token *)node->content;
		printf("[%d] %d {%s}\n", count++, token->type, token->content);
		node = node->next;
	}
}
