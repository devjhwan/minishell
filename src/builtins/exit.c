/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:37:42 by jmarinel          #+#    #+#             */
/*   Updated: 2023/12/14 12:48:34 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "err_msg.h"

static long long	exit_mod(long long num)
{
	if (num < 0)
		num = num % (256 * 2);
	else
		num %= 256;
	return (num);
}

int	exit_sh(char **args, int *exit_code)
{
	if (args[2] == NULL && ft_strncmp(args[1], "--", 3) == 0)
		exit(0);
	if (args[1])
	{
		if (ft_islonglong(args[1]) || is_num(args[1]))
		{
			ft_perror(NUMERIC_ARGUMENT, args[1]);
			exit(255);
		}
		else if (ft_arraylen(args) > 2)
		{
			ft_perror(TOO_MANY_ARGS, args[1]);
			*exit_code = 1;
			return (ERROR);
		}
		//ft_printf_fd(2, "exit\n");
		exit(exit_mod(ft_atoll(args[1])));
	}
	//ft_printf_fd(2, "exit\n");
	exit(*exit_code);
}
