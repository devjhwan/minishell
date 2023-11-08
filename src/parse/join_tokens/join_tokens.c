/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_tokens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 01:51:07 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/08 03:43:03 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_list	*join_tokens(t_list *token_list)
{
	token_list = join_arguments(token_list);
	if (token_list == NULL)
		return (NULL);
	token_list = join_env_var_arguments(token_list);
	if (token_list == NULL)
		return (NULL);
	token_list = join_redirections(token_list);
	if (token_list == NULL)
		return (NULL);
	return (token_list);
}
