/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:30:56 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/07 15:48:36 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	list_clear(t_list *list, void (*del_func)(void *))
{
	t_list_node	*del_node;

	while (list->header)
	{
		del_node = list->header;
		list->header = list->header->next;
		if (del_func != NULL)
			del_func(del_node->content);
		free(del_node);
	}
	free(list);
}
