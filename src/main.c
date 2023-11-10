/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:42:54 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/10 04:01:39 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"
#include "libft.h"
#include <signal.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>

void	handler(int signum)
{
	if (signum == SIGINT)
	{
		write(STDOUT_FILENO, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
	}
}

static void	init_minishell(int *exit_code)
{
	signal(SIGINT, handler);
	*exit_code = 0;
}

static void	test_get_command(t_list *command_list)
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

int	main(int argc, char **argv, char **envp)
{
	char	*str;
	t_list	*command_list;
	int		exit_code;

	(void)argc;
	(void)argv;
	init_minishell(&exit_code);
	while (1)
	{
		str = readline("prompt: ");
		if (str == NULL)
			break ;
		if (ft_strncmp(str, "exit", 5) == 0)
			return (free(str), 0);
		add_history(str);
		command_list = parse_input(str, envp, &exit_code);
		if (command_list != NULL)
		{
			test_get_command(command_list);
			list_clear(command_list, free_command);
		}
		free(str);
	}
	return (0);
}
