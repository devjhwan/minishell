/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 23:04:56 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/06 23:12:28 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include <stdlib.h>

t_tree	*tree_init(void)
{
	t_tree	*tree;

	tree = (t_tree)malloc(sizeof(t_tree));
	if (tree == NULL)
		return (NULL);
	tree->root = NULL;
	tree->size = 0;
	return (tree);
}
