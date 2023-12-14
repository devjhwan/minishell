/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:03:58 by junghwle          #+#    #+#             */
/*   Updated: 2023/12/14 11:14:38 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

t_list	*expander(t_list *parse_list, t_minishell *shell)
{
	if (expand_env_variables(parse_list, shell) == NULL)
		return (NULL);
	// print_token_list(parse_list);
	if (clear_empty_nodes(parse_list) == NULL)
		return (NULL);
	// printf("\n");
	// print_token_list(parse_list);
	if (split_blank_from_env(parse_list, shell) == NULL)
		return (NULL);
	// printf("\n");
	// print_token_list(parse_list);
	if (expand_home_character(parse_list, shell) == NULL)
		return (NULL);
	// printf("\n");
	// print_token_list(parse_list);
	if (remove_quotes(parse_list) == NULL)
		return (NULL);
	// printf("\n");
	// print_token_list(parse_list);
	if (env_to_arg(parse_list, shell) == NULL)
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
