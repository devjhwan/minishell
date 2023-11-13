/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_builder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:04:11 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/13 17:20:30 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"
#include "libft.h"

static char	*append_content(t_list *list, char *content)
{
	char	*str;

	str = ft_strdup(content);
	if (str == NULL)
		return (NULL);
	if (list_append(list, str) == NULL)
		return (free(str), NULL);
	return (str);
}

static t_command	*get_new_command(t_command *new_command, \
					t_list_node **node, t_list *command_list)
{
	t_token		*cur_token;

	cur_token = (t_token *)(*node)->content;
	while (*node != NULL && cur_token->type != PIPE)
	{
		if (cur_token->type == RD)
		{
			if (append_content(new_command->redirection, \
							(char *)cur_token->content) == NULL)
				return (free_command(new_command), NULL);
		}
		else
		{
			if (append_content(new_command->command, \
							(char *)cur_token->content) == NULL)
				return (free_command(new_command), NULL);
		}
		*node = (*node)->next;
		if (*node != NULL)
			cur_token = (t_token *)(*node)->content;
	}
	if (command_list->last != NULL && new_command != NULL)
		((t_command *)command_list->last->content)->next = new_command;
	return (new_command);
}

static t_list	*create_command_list(t_lis *expander_list)
{
	t_list		*command_list;
	t_list_node	*cur_node;
	t_command	*new_command;

	command_list = list_init();
	if (command_list == NULL)
		return (NULL);
	cur_node = expander_list->header;
	while (cur_node != NULL)
	{
		new_command = create_command();
		if (new_command == NULL)
			return (list_clear(command_list, free_command), NULL);
		if (get_new_command(new_command, &cur_node, command_list) == NULL)
			return (list_clear(command_list, free_command), NULL);
		if (list_append(command_list, new_command) == NULL)
			return (list_clear(command_list, free_command), \
					free_command(new_command), NULL);
		if (cur_node != NULL)
			cur_node = cur_node->next;
	}
	return (command_list);
}

t_cmnd	*command_builder(t_list *expander_list)
{
	t_list		*command_list;
	t_cmnd		*cmnd_list;

	command_list = create_command_list(expander_list);
	list_clear(expander_list, free_token);
	if (command_list == NULL)
		return (NULL);
	cmnd_list = translate_command_list(command_list);
	list_clear(command_list, free_token);
	if (cmnd_list == NULL)
		return (NULL);
	return (cmnd_list);
}
