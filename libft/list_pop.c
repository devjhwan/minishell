/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_pop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:37:31 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/06 23:15:17 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	*list_pop(t_list *list)
{
	t_list_node	*del_node;
	void		*content;

	if (list->size == 0)
		return (NULL);
	del_node = list->header;
	list->header = list->header->next;
	content = del_node->content;
	free(del_node);
	list->size--;
	if (list->size == 0)
	{
		list->header = NULL;
		list->last = NULL;
	}
	return (content);
}
