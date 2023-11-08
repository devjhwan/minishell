/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:42:54 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/08 16:41:32 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
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

int	main(int argc, char **argv, char **envp)
{
	char	*str;
	t_list	*command_list;

	(void)argc;
	(void)argv;
	(void)envp;
	signal(SIGINT, handler);
	while (1)
	{
		str = readline("prompt: ");
		if (str == NULL)
			break ;
		if (ft_strncmp(str, "exit", 5) == 0)
			return (free(str), 0);
		add_history(str);
		command_list = parse_input(str, envp);
		if (command_list == NULL)
			exit(1);
		list_clear(command_list, free_command);
		free(str);
	}
	return (0);
}
