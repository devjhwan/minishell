/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 23:06:34 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/07 19:29:13 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include <stdio.h>

static void	free_node(t_tree_node *node, void (*del_func)(void *))
{
	if (node->left != NULL)
		free_node(node->left, del_func);
	if (node->right != NULL)
		free_node(node->right, del_func);
	if (del_func != NULL)
		del_func(node->content);
	free(node);
}

void	tree_clear(t_tree *tree, void (*del_func)(void *))
{
	if (tree->size > 0)
		free_node(tree->root, del_func);
	free(tree);
}
