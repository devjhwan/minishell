/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_token_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:56:01 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/09 19:19:04 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

static int	check_redirection(t_list_node *cur_node, int *exit_code)
{
	(void)cur_node;
	(void)exit_code;
	return (0);
}

static int	check_pipe(t_list *token_list, t_list_node *cur_node, \
						int *exit_code)
{
	(void)token_list;
	(void)cur_node;
	(void)exit_code;
	return (0);
}

t_list	*check_token_error(t_list *token_list, int *exit_code)
{
	t_list_node	*cur_node;
	t_token		*cur_token;
	int			ret;

	(void)exit_code;
	return (token_list);
	if (token_list->size == 0)
		return (token_list);
	cur_node = token_list->header;
	while (cur_node != NULL)
	{
		cur_token = (t_token *)cur_node->content;
		if (cur_token->type == RD)
			ret = check_redirection(cur_node, exit_code);
		else if (cur_token->type == PIPE)
			ret = check_pipe(token_list, cur_node, exit_code);
		if (ret == 1)
			return (free(token_list), NULL);
	}
	return (token_list);
}
