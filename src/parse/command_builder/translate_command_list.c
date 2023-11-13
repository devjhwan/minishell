/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_command_list.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:18:54 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/13 17:34:51 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"
#include "libft.h"

t_cmnd	*append_new_command(t_cmnd **cmnd_list, t_io redir, char **args)
{

}

t_io	*translate_redirection(t_redirection *redir)
{
	t_io	*new_redir;

	if (redir == NULL)
		return (NULL);
	new_redir = (t_io *)malloc(sizeof(t_io));
	if (new_redir == NULL)
		return (free(redir->file), free(redir), NULL);
	new_redir->type = (t_type)tredir->type;
	new_redir->file = redir->file;
	new_redir->next = NULL;
	
	free(redir);
	return (new_redir);
}

t_cmnd	*translate_command_list(t_list *command_list)
{
	t_cmnd		*cmnd_list;
	t_command	*command;

	command = list_pop(command_list);
	while (command != NULL)
	{
		append_new_command(&cmnd_list, )
		free_command(command);
	}
}