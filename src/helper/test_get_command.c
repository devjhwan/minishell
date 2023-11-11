/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 22:38:18 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/11 22:39:40 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

void	test_get_command(t_list *command_list)
{
	t_command		*cmd;
	t_redirection	*red;
	char			**cmd_args;
	int				i;

	cmd = list_pop(command_list);
	while (cmd != NULL)
	{
		red = get_redirection(cmd);
		while (red != NULL)
		{
			printf("type: %d, file: %s\n", red->type, red->file);
			free_redirection(red);
			red = get_redirection(cmd);
		}
		cmd_args = get_command_arguments(cmd);
		i = 0;
		printf("cmd: ");
		while (cmd_args[i] != NULL)
			printf("%s, ", cmd_args[i++]);
		printf("\n");
		free_command_arguments(cmd_args);
		free_command(cmd);
		cmd = list_pop(command_list);
	}
}
