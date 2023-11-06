/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:56:24 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/06 23:13:00 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdlib.h>

t_token	*create_token(void *content)
{
	t_token	*new_token;

	new_token = (t_token *)malloc(sizeof(t_token));
	if (new_token == NULL)
		return (NULL);
	new_token->content = content;
	return (new_token);
}

void	free_token(void	*token)
{
	t_token	*del_token;

	del_token = (t_token *)token;
	free(del_token);
}
