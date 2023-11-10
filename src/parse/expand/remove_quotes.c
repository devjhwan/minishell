/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 02:37:10 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/10 03:10:16 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

static void	remove_rd_quote(char *argument)
{
	int	i;

	i = 0;
	while (argument[i] == '<' || argument[i] == '>')
		i++;
	if (isquote(argument[i]))
		ft_strlcpy(&argument[i], &argument[i + 1], ft_strlen(&argument[i]) - 1);
}

t_list	*remove_quotes(t_list *parse_list)
{
	t_list_node	*cur_node;
	t_token		*cur_token;
	char		*argument;

	cur_node = parse_list->header;
	while (cur_node != NULL)
	{
		cur_token = (t_token *)cur_node->content;
		argument = (char *)cur_token->content;
		if (cur_token->type == RD)
			remove_rd_quote(argument);
		else
			if (isquote(argument[0]))
				ft_strlcpy(argument, argument + 1, ft_strlen(argument) - 1);
		cur_node = cur_node->next;
	}
	return (parse_list);
}
