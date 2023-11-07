/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_new_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:29:55 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/07 19:30:04 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

t_tree_node	*tree_new_node(void *content)
{
	t_tree_node	*new_node;

	new_node = (t_tree_node *)malloc(sizeof(t_tree_node));
	if (new_node == NULL)
		return (NULL);
	new_node->content = content;
	new_node->left = NULL;
	new_node->right = NULL;
	return (new_node);
}
