/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:03:58 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/09 02:42:39 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

t_list	*expander(t_list *parse_list, char **envp)
{
	if (expand_env_variables(parse_list, envp) == NULL)
		return (NULL);
	if (remove_quotes(parse_list) == NULL)
		return (NULL);
	return (parse_list);
}

/*
$ENV, "$ENV", '$ENV'
*/
