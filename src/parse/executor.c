/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:04:11 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/07 15:32:31 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_list	*executor(t_tree *parse_tree)
{
	t_list	*command_list;

	if (parse_tree == NULL)
		return (NULL);
	command_list = list_init();
	if (command_list == NULL)
		return (tree_clear(parse_tree, free_token), NULL);
	(void)parse_tree;
	return (tree_clear(parse_tree, free_token), command_list);
}
