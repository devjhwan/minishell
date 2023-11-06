/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:57:14 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/06 22:57:26 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdlib.h>

t_command	*create_command(void *content)
{
	t_command	*new_command;

	new_command = (t_command *)malloc(sizeof(t_command));
	if (new_command == NULL)
		return (NULL);
	new_command->content = content;
	return (new_command);
}

void	free_command(void *command)
{
	t_command	*del_command;

	del_command = (t_command *)command;
	free(del_command);
}