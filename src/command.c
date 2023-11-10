/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:57:14 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/10 03:15:05 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>

t_command	*create_command(void)
{
	t_command	*new_command;

	new_command = (t_command *)malloc(sizeof(t_command));
	if (new_command == NULL)
		return (NULL);
	new_command->redirection = list_init();
	if (new_command->redirection == NULL)
		return (free(new_command), NULL);
	new_command->command = list_init();
	if (new_command->command == NULL)
		return (free(new_command), free(new_command->redirection), NULL);
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
