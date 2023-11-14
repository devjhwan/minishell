/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_command_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 23:37:19 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/14 00:11:08 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_redirection(t_io *redir)
{
	t_io	*delredir;

	while (redir != NULL)
	{
		delredir = redir;
		redir = redir->next;
		free(delredir->file);
		free(delredir);
	}
}

void	free_arguments(char **args)
{
	int		i;

	if (args == NULL)
		return ;
	i = 0;
	while (args[i] != NULL)
		free(args[i++]);
	free(args);
}

void	free_cmnd_list(t_cmnd **cmnd_list)
{
	t_cmnd	*delcmnd;

	if (cmnd_list == NULL)
		return ;
	while (*cmnd_list != NULL)
	{
		delcmnd = *cmnd_list;
		*cmnd_list = (*cmnd_list)->next;
		free_redirection(delcmnd->redir);
		free_arguments(delcmnd->args);
		free(delcmnd);
	}
	*cmnd_list = NULL;
}
