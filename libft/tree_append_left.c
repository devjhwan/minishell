/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_append_left.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:24:56 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/07 13:32:37 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

t_tree_node	*tree_append_left(t_tree_node *cur_node, void *content)
{
	t_tree_node	*new_node;

	new_node = tree_new_node(content);
	if (new_node == NULL)
		return (NULL);
	if (cur_node->left != NULL)
		new_node->left = cur_node->left;
	cur_node->left = new_node;
	return (new_node);
}