/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 23:27:24 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/09 23:56:13 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "err_msg.h"

int	check_pipe(t_list *token_list, t_list_node *cur_node, int *exit_code)
{
	t_list_node	*prev_node;
	t_list_node	*next_node;

	if (cur_node == token_list->header)
	{
		*exit_code = 2;
		ft_perror(UNEXPECTED_TOKEN, "|");
		return (1);
	}
	prev_node = token_list->header;
	next_node = cur_node->next;
	while (prev_node->next != cur_node)
		prev_node = prev_node->next;
	if (((t_token *)prev_node->content)->type == PIPE || next_node == NULL || \
		((t_token *)next_node->content)->type == PIPE)
	{
		*exit_code = 2;
		ft_perror(UNEXPECTED_TOKEN, "|");
		return (1);
	}
	return (0);
}
