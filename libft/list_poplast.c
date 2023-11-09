/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_poplast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:32:37 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/09 18:01:32 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	*list_poplast(t_list *list)
{
	t_list_node	*cur_node;
	void		*content;

	if (list->size == 0)
		return (NULL);
	content = list->last->content;
	free(list->last);
	list->size--;
	if (list->size == 0)
	{
		list->header = NULL;
		list->last = NULL;
	}
	else
	{
		cur_node = list->header;
		while (cur_node->next != list->last)
			cur_node = cur_node->next;
		list->last = cur_node;
		list->last->next = NULL;
	}
	return (content);
}
