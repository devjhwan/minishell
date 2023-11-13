/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_argument.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 03:33:42 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/10 04:09:50 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

char	**get_command_arguments(t_command *command)
{
	char	**arguments;
	char	*cmd_arguments;
	int		i;

	arguments = (char **)malloc(sizeof(char *) * (command->command->size + 1));
	if (arguments == NULL)
		return (NULL);
	i = 0;
	cmd_arguments = (char *)list_pop(command->command);
	while (cmd_arguments != NULL)
	{
		arguments[i] = cmd_arguments;
		cmd_arguments = (char *)list_pop(command->command);
		i++;
	}
	arguments[i] = NULL;
	return (arguments);
}

void	free_command_arguments(char **cmd_arguments)
{
	int	i;

	i = 0;
	while (cmd_arguments[i] != NULL)
		free(cmd_arguments[i++]);
	free(cmd_arguments);
}
