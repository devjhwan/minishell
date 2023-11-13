/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinel <jmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:42:54 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/13 16:36:06 by jmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"
#include "libft.h"
#include "pipe.h"
#include <signal.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

t_cmnd	*append_cmnd(t_cmnd **list, t_redirection *red, char **args)
{
	t_cmnd	*new_cmnd;
	t_cmnd	*tmp;
	t_io	*redir;	

	new_cmnd = (t_cmnd *)malloc(sizeof(t_cmnd));
	if (new_cmnd == NULL)
		return (NULL);
	redir = (t_io *)malloc(sizeof(t_io));
	if (redir == NULL)
		return (free(new_cmnd), NULL);
	ft_memcpy((void *)redir, (void *)red, sizeof(t_redirection));
	new_cmnd->redir = red;
	new_cmnd->args = args;
	new_cmnd->next = NULL;
	tmp = *list;
	if (tmp == NULL)
		*list = new_cmnd;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_cmd;
	}
}

void	free_cmnd_list(t_cmnd *cmnd)
{
	
}

t_cmnd	*create_cmnd_list(t_minishell *shell)
{
	t_cmnd		*prev_cmnd;
	t_command	*cur_command;

	cur_command = list_pop(shell->command_list);
	shell->cmnd_list = NULL;
	while (cur_command != NULL)
	{
		if (append_cmnd(shell->cmnd_list, cur_))
		free_command(cur_command);
		cur_command = list_pop(shell->command_list);
	}
	free(shell->command_list);
	return (shell->cmnd_list);
}

int	main(int argc, char **argv, char **envp)
{
	char		*str;
	t_minishell	shell;

	init_minishell(argc, argv, envp, &shell);
	while (1)
	{
		set_minishell_terminal();
		str = readline("prompt: ");
		if (str == NULL)
			break ;
		add_history(str);
		shell.command_list = parse_input(str, envp, &shell.exit_code);
		rollback_terminal_setting();
		free(str);
		if (shell.command_list == NULL)
			continue ;
		
		executor(&shell);
		list_clear(shell.command_list, free_command);
		shell.command_list = NULL;
	}
	free_minishell(shell);
	return (rollback_terminal_setting(), 0);
}
