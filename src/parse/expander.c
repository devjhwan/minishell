/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:03:58 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/08 17:26:43 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

char	*expand_env_variable(char *argument, char **envp)
{
	(void)argument;
	(void)envp;
	return (ft_strdup(argument));
}

t_list	*expander(t_list *parse_list, char **envp)
{
	t_list_node	*cur_node;
	t_token		*cur_token;
	char		*argument;
	char		*new_argument;

	cur_node = parse_list->header;
	while (cur_node != NULL)
	{
		cur_token = (t_token *)cur_node->content;
		argument = (char *)cur_token->content;
		if (ft_strchr(argument, '$') != NULL)
		{
			new_argument = expand_env_variable(argument, envp);
			if (new_argument == NULL)
				return (list_clear(parse_list, free_token), NULL);
			free(argument);
			cur_token->content = (void *)new_argument;
		}
		cur_node = cur_node->next;
	}
	return (parse_list);
}

/*
$ENV, "$ENV", '$ENV'
*/
