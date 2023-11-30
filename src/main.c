/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:42:54 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/30 13:00:29 by junghwle         ###   ########.fr       */
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
		printf("redirections:\n");
		while (redir != NULL)
		{
			printf("\ttype: %d, file: %s\n", redir->type, redir->file);
			redir = redir->next;
		}
		i = 0;
		printf("arguments:\n");
		while (args != NULL && args[i] != NULL)
			printf("\targ: %s\n", args[i++]);
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
		set_minishell_terminal();
		str = readline("prompt: ");
		if (str == NULL)
			break ;
		add_history(str);
		shell.cmnd_list = parse_input(str, &shell);
		rollback_terminal_setting();
		free(str);
		print_cmnd_list(shell.cmnd_list);
		if (shell.cmnd_list == NULL)
			continue ;
		//executer(shell.cmnd_list, shell._envp, &shell.exit_code, &shell);
		free_cmnd_list(&shell.cmnd_list);
		shell.cmnd_list = NULL;
	}
	free_minishell(shell);
	return (rollback_terminal_setting(), 0);
}
