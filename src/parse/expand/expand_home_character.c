/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_home_character.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinel <jmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 02:41:07 by junghwle          #+#    #+#             */
/*   Updated: 2023/12/14 15:21:21 by jmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

t_list	*replace_argument(t_list *parse_list, t_minishell *shell, \
							t_list_node *cur_node)
{
	t_token		*cur_token;
	char		*argument;
	char		*new_argument;

	cur_token = (t_token *)cur_node->content;
	argument = (char *)cur_token->content;
	if (((ft_strncmp(argument, "~", 2) == 0 && (cur_node->next == NULL || \
		(cur_node->next != NULL && \
		((t_token *)cur_node->next->content)->content[0] != '$'))) || \
		ft_strncmp(argument, "~/", 2) == 0))
	{
		new_argument = (char *)malloc(sizeof(char) * 1000);
		if (new_argument == NULL)
			return (NULL);
		ft_strlcpy(new_argument, shell->home, 1000);
		ft_strlcat(new_argument, &argument[1], 1000);
		free(cur_token->content);
		cur_token->content = (void *)new_argument;
	}
	return (parse_list);
}

t_list	*expand_home_character(t_list *parse_list, t_minishell *shell)
{
	t_list_node	*cur_node;

	cur_node = parse_list->header;
	while (cur_node != NULL)
	{
		if (replace_argument(parse_list, shell, cur_node) == NULL)
			return (list_clear(parse_list, free_token), NULL);
		cur_node = cur_node->next;
	}
	return (parse_list);
}
