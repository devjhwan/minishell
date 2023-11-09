/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:57:14 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/09 17:56:36 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdlib.h>

t_command	*create_command(t_list *redirection, t_list *command)
{
	t_command	*new_command;

	new_command = (t_command *)malloc(sizeof(t_command));
	if (new_command == NULL)
		return (NULL);
	new_command->redirection = redirection;
	new_command->command = command;
	return (new_command);
}

void	free_command(void *command)
{
	t_command	*del_command;

	del_command = (t_command *)command;
	list_clear(del_command->redirection, free);
	list_clear(del_command->command, free);
	free(del_command);
}
/*
[redirection_list, command_list]
[[<infile1, <infile2, >outfile1, >>outfile2, <<END],
 [cat, file1, file2, file3, file4...]]
*/
