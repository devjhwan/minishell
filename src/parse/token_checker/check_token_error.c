/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_token_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:56:01 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/10 01:13:46 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "err_msg.h"

t_list	*check_token_error(t_list *token_list, char **envp, int *exit_code)
{
	t_list_node	*cur_node;
	t_token		*cur_token;
	int			ret;

	if (token_list->size == 0)
		return (token_list);
	cur_node = token_list->header;
	ret = 0;
	while (cur_node != NULL)
	{
		cur_token = (t_token *)cur_node->content;
		if (cur_token->type == RD)
			ret = check_redirection(cur_node, envp, exit_code);
		else if (cur_token->type == PIPE)
			ret = check_pipe(token_list, cur_node, exit_code);
		if (ret < 0 || ret == 1)
			return (list_clear(token_list, free_token), NULL);
		cur_node = cur_node->next;
	}
	return (token_list);
}
