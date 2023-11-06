/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:03:32 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/06 23:12:55 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdlib.h>

static t_tree	*init_tree(void)
{
	t_tree	*parse_tree;

	parse_tree = NULL;
	return (parse_tree);
}

void	free_tree(t_tree *parse_tree)
{
	free(parse_tree);
}

t_tree	*parser(t_list	*token_list)
{
	t_tree	*parse_tree;

	if (token_list == NULL)
		return (NULL);
	parse_tree = init_tree();
	if (parse_tree == NULL)
		return (free_token(token_list), NULL);
	(void)token_list;
	return (list_clear(token_list, free_token), parse_tree);
}
