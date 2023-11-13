/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:42:54 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/13 17:27:03 by junghwle         ###   ########.fr       */
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
		shell.cmnd_list = parse_input(str, envp, &shell.exit_code);
		rollback_terminal_setting();
		free(str);
		if (shell.cmnd_list == NULL)
			continue ;
		executor(&shell);
		clear_command_list(shell.cmnd_list);
		shell.command_list = NULL;
	}
	free_minishell(shell);
	return (rollback_terminal_setting(), 0);
}
