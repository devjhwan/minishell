/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_builder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:04:11 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/30 13:08:21 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include <errno.h>

static char	**get_command_arguments(t_list_node *cur_node, int count, int i)
{
	char		**args;
	t_list_node	*tmp;

	tmp = cur_node;
	while (tmp != NULL && ((t_token *)tmp->content)->type != PIPE)
	{
		if (((t_token *)tmp->content)->type == ARG)
			count++;
		tmp = tmp->next;
	}
	if (count == 0)
		return (NULL);
	args = (char **)malloc(sizeof(char *) * (count + 1));
	if (args == NULL)
		return (NULL);
	while (cur_node != NULL && ((t_token *)cur_node->content)->type != PIPE)
	{
		if (((t_token *)cur_node->content)->type == ARG)
			args[i++] = ft_strdup(((t_token *)cur_node->content)->content);
		if (i >= 1 && args[i - 1] == NULL)
			return (free_arguments(args), NULL);
		cur_node = cur_node->next;
	}
	args[i] = NULL;
	return (args);
}

static t_io	*create_redirection(char *redir_argument)
{
	t_io	*new_redir;

	new_redir = (t_io *)malloc(sizeof(t_io));
	if (new_redir == NULL)
		return (NULL);
	new_redir->file = ft_strdup(ft_strchr(redir_argument, ' ') + 1);
	if (new_redir->file == NULL)
		return (free(new_redir), NULL);
	if (redir_argument[1] == '<')
		new_redir->type = HERE_DOC;
	else if (redir_argument[1] == '>')
		new_redir->type = OUT_APPEND;
	else if (redir_argument[0] == '<')
		new_redir->type = IN;
	else if (redir_argument[0] == '>')
		new_redir->type = OUT;
	else
		new_redir->type = NO_REDIR;
	new_redir->next = NULL;
	return (new_redir);
}

static t_io	*get_redirections(t_list_node *cur_node)
{
	t_token	*cur_token;
	t_io	*redir_list;
	t_io	*new_redir;
	t_io	*last_redir;

	cur_token = (t_token *)cur_node->content;
	redir_list = NULL;
	while (cur_node != NULL && cur_token->type != PIPE)
	{
		if (cur_token->type == RD)
		{
			new_redir = create_redirection((char *)cur_token->content);
			if (new_redir == NULL)
				return (free_redirection(redir_list), NULL);
			if (redir_list == NULL)
				redir_list = new_redir;
			else
				last_redir->next = new_redir;
			last_redir = new_redir;
		}
		cur_node = cur_node->next;
		if (cur_node != NULL)
			cur_token = (t_token *)cur_node->content;
	}
	return (redir_list);
}

static t_cmnd	*create_new_command(t_list_node *cur_node)
{
	t_cmnd	*new_cmnd;

	new_cmnd = (t_cmnd *)malloc(sizeof(t_cmnd));
	if (new_cmnd == NULL)
		return (NULL);
	errno = 0;
	new_cmnd->args = get_command_arguments(cur_node, 0, 0);
	if (errno != 0)
		return (free(new_cmnd), NULL);
	new_cmnd->redir = get_redirections(cur_node);
	if (errno != 0)
		return (free(new_cmnd), free_arguments(new_cmnd->args), NULL);
	new_cmnd->next = NULL;
	return (new_cmnd);
}

t_cmnd	*command_builder(t_list *expander_list)
{
	t_cmnd		*cmnd_list;
	t_cmnd		*new_cmnd;
	t_cmnd		*last_cmnd;
	t_list_node	*cur_node;

	cmnd_list = NULL;
	cur_node = expander_list->header;
	while (cur_node != NULL)
	{
		new_cmnd = create_new_command(cur_node);
		if (new_cmnd == NULL)
			return (list_clear(expander_list, free_token), \
					free_cmnd_list(&cmnd_list), NULL);
		while (cur_node != NULL && \
				((t_token *)cur_node->content)->type != PIPE)
			cur_node = cur_node->next;
		if (cur_node != NULL)
			cur_node = cur_node->next;
		if (cmnd_list == NULL)
			cmnd_list = new_cmnd;
		else
			last_cmnd->next = new_cmnd;
		last_cmnd = new_cmnd;
	}
	return (list_clear(expander_list, free_token), cmnd_list);
}
