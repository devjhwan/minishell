/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:56:24 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/08 03:18:44 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdlib.h>

t_token	*create_token(char type, char *content)
{
	t_token	*new_token;

	if (content == NULL)
		return (NULL);
	new_token = (t_token *)malloc(sizeof(t_token));
	if (new_token == NULL)
		return (free(content), NULL);
	new_token->type = type;
	new_token->content = content;
	return (new_token);
}

void	free_token(void	*token)
{
	t_token	*del_token;

	del_token = (t_token *)token;
	free(del_token->content);
	free(del_token);
}
