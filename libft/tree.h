/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:59:17 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/07 16:12:09 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_H
# define TREE_H

# include <stdlib.h>

typedef struct s_tree_node
{
	void				*content;
	struct s_tree_node	*left;
	struct s_tree_node	*right;
}	t_tree_node;

typedef struct s_tree
{
	t_tree_node	*root;
	int			size;
}	t_tree;

t_tree		*tree_init(void);
void		tree_clear(t_tree *tree, void (*del_func)(void *));
t_tree_node	*tree_new_node(void *content);
t_tree_node	*tree_append_left(t_tree_node *cur_node, void *content);
t_tree_node	*tree_append_right(t_tree_node *cur_node, void *content);

#endif