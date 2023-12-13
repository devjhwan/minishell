/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:42:54 by junghwle          #+#    #+#             */
/*   Updated: 2023/12/13 17:53:36 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"
#include "libft.h"
#include "executer.h"
#include <signal.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

void	print_cmnd_list(t_cmnd *cmnd_list)
{
	t_io	*redir;
	char	**args;
	int		i;

	while (cmnd_list != NULL)
	{
		redir = cmnd_list->redir;
		args = cmnd_list->args;
		ft_printf("redirections:\n");
		while (redir != NULL)
		{
			ft_printf("\ttype: %d, file: %s$\n", redir->type, redir->file);
			redir = redir->next;
		}
		i = 0;
		ft_printf("arguments:\n");
		while (args != NULL && args[i] != NULL)
			ft_printf("\targ: %s\n", args[i++]);
		cmnd_list = cmnd_list->next;
	}
}

int	main(int argc, char **argv, char **envp)
{
	char		*str;
	t_minishell	shell;

	init_minishell(argc, argv, envp, &shell);
	while (1)
	{
		set_default_minishell_signal();
		set_minishell_terminal();
		str = readline("prompt: ");
		if (str == NULL)
			break ;
		add_history(str);
		shell.cmnd_list = parse_input(str, &shell);
		free(str);
		if (shell.cmnd_list == NULL)
			continue ;
		//print_cmnd_list(shell.cmnd_list);
		rollback_terminal_setting();
		set_execution_signal();
		executer(shell.cmnd_list, &shell);
		free_cmnd_list(&shell.cmnd_list);
		shell.cmnd_list = NULL;
	}
	return (rollback_terminal_setting(), free_minishell(shell));
}
