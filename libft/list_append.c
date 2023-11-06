/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_append.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:34:28 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/06 23:11:52 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

t_list_node	*list_append(t_list *list, void *content)
{
	t_list_node	*new_node;

	new_node = (t_list_node *)malloc(sizeof(t_list_node));
	if (new_node == NULL)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	if (list->size == NULL)
	{
		list->header = new_node;
		list->last = new_node;
	}
	else
	{
		list->last->next = new_node;
		list->last = new_node;
	}
	list->size++;
	return (new_node);
}
