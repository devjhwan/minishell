/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:03:58 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/14 01:11:03 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

t_list	*expander(t_list *parse_list, t_minishell *shell)
{
	if (expand_env_variables(parse_list, shell) == NULL)
		return (NULL);
	if (remove_quotes(parse_list) == NULL)
		return (NULL);
	return (parse_list);
}

/*
$ENV, "$ENV", '$ENV'
*/
