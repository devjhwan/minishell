/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:04:11 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/07 19:26:38 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_list	*executor(t_tree *expander_tree)
{
	t_list	*command_list;

	command_list = list_init();
	if (command_list == NULL)
		return (tree_clear(expander_tree, free_token), NULL);
	return (tree_clear(expander_tree, free_token), command_list);
}
