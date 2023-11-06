/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:04:11 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/06 22:58:42 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "list.h"

t_list	*executor(t_tree *parse_tree)
{
	t_list	*command_list;

	if (parse_tree == NULL)
		return (NULL);
	command_list = list_init();
	if (command_list == NULL)
		return (free_tree(parse_tree), NULL);
	(void)parse_tree;
	return (free_tree(parse_tree), command_list);
}