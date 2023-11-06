/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:59:17 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/06 23:16:14 by junghwle         ###   ########.fr       */
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
	int					len;
}	t_tree_node;

typedef struct s_tree
{
	t_tree_node	*root;
	int			size;
}	t_tree;

t_tree	*tree_init(void);
void	tree_clear(t_tree *tree, void (*del_func)(void *));

#endif