/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:28:01 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/06 23:16:19 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <stdlib.h>

typedef struct s_list_node
{
	void				*content;
	struct s_list_node	*next;
}	t_list_node;

typedef struct s_list
{
	t_list_node	*header;
	t_list_node	*last;
	int			size;
}	t_list;

t_list		*list_init(void);
void		list_clear(t_list *list, void (*del_func)(void *));
t_list_node	*list_append(t_list *list, void *content);
void		*list_pop(t_list *list);

#endif