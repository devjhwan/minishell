/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:03:58 by junghwle          #+#    #+#             */
/*   Updated: 2023/12/13 17:47:11 by junghwle         ###   ########.fr       */
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
	parse_list = merge_consecutive_arguments(parse_list);
	if (parse_list == NULL)
		return (NULL);
	parse_list = remove_blanks(parse_list);
	if (parse_list == NULL)
		return (NULL);
	return (parse_list);
}

/*
$ENV, "$ENV", '$ENV'
*/
