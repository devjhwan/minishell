/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_command_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 02:00:58 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/10 02:29:02 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

static void	print_list(t_list_node *node)
{
	printf("\t[");
	while (node != NULL)
	{
		printf("%s", (char *)node->content);
		node = node->next;
		if (node != NULL)
			printf(", ");
	}
	printf("]\n");
}

void	print_command_list(t_list *command_list)
{
	t_list_node	*node;
	t_command	*command;

	node = command_list->header;
	while (node != NULL)
	{
		command = (t_command *)node->content;
		printf("[\n");
		print_list(command->redirection->header);
		print_list(command->command->header);
		printf("]\n");
		node = node->next;
	}
}
