/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_to_Arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 02:41:07 by junghwle          #+#    #+#             */
/*   Updated: 2023/12/14 11:16:25 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

t_list	*env_to_arg(t_list *parse_list, t_minishell *shell)
{
	t_list_node	*cur_node;
	t_token		*cur_token;
	char		*argument;

	cur_node = parse_list->header;
	while (cur_node != NULL)
	{
		cur_token = (t_token *)cur_node->content;
		if (cur_token->type == ENV)
		{
			argument = (char *)cur_token->content;
			if (isquote(argument[0]))
			{
				ft_strlcpy(argument, argument + 1, ft_strlen(argument) - 1);
				cur_token->type = ARG;
			}
			else if (split_argument(cur_node, shell, argument) == 1)
				return (list_clear(parse_list, free_token), NULL);
		}
		cur_node = cur_node->next;
	}
	return (parse_list);
}
