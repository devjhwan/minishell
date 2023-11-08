/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:04:11 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/08 15:45:33 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_list	*executor(t_list *expander_list)
{
	t_list	*command_list;

	command_list = list_init();
	if (command_list == NULL)
		return (list_clear(expander_list, free_token), NULL);
	return (list_clear(expander_list, free_token), command_list);
}
