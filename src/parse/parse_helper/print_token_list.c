/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_token_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinel <jmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:21:12 by junghwle          #+#    #+#             */
/*   Updated: 2023/12/13 17:45:34 by jmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdio.h>
#include "libft.h"

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
		ft_printf("[%d] %d {%s}\n", count++, token->type, token->content);
		node = node->next;
	}
}
