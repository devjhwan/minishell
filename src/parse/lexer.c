/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:03:40 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/06 22:58:27 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "list.h"

t_list	*lexer(char *line)
{
	t_list	*token_list;
	
	if (line == NULL)
		return (NULL);
	token_list = list_init();
	if (token_list == NULL)
		return (NULL);
	(void)line;
	return (token_list);
}