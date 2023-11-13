/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_command_list.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:18:54 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/13 17:48:34 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"
#include "libft.h"

static void	clear(t_io *redir, char **args)
{
	if (redir != NULL)
	{

	}
}

static t_cmnd	*append_new_command(t_cmnd **cmnd_list, \
									t_io *redir, char **args)
{
	if (redir == NULL || args == NULL)
}

static t_io	*append_redir(t_io **redir_list, t_io *new_redir)
{

}

static t_io	*translate_redirection(t_command *command)
{
	t_io			*redir_list;
	t_io			*new_redir;
	t_redirection	*redir;

	redir = get_redirection(command);
	while (redir != NULL)
	{
		new_redir = (t_io *)malloc(sizeof(t_io));
		if (new_redir == NULL)
			return (free(redir->file), free(redir), NULL);
		new_redir->type = (t_type)tredir->type;
		new_redir->file = redir->file;
		new_redir->next = NULL;
		if (redir_list == NULL)
			redir_list = new_redir;
		if (append_redir(&redir_list, new_redir) == NULL)
			return (clear(redir_list, NULL), NULL);
		free_redirection(redir);
		redir = get_redirection(command);
	}
	return (new_redir);
}

t_cmnd	*translate_command_list(t_list *command_list)
{
	t_cmnd		*cmnd_list;
	t_command	*command;

	command = list_pop(command_list);
	while (command != NULL)
	{
		if (append_new_command(&cmnd_list, \
				translate_redirection(command),
				get_command_arguments(command)) == NULL)
			return (clear_command_list(cmnd_list), NULL);
		free_command(command);
	}
	return (cmnd_list);
}