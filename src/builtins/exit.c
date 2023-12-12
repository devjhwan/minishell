/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinel <jmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:37:42 by jmarinel          #+#    #+#             */
/*   Updated: 2023/12/12 11:31:45 by jmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

int	exit_sh(char **args, int *exit_code)
{
	if (args[1])
	{
		if (ft_atoll(args[1]))
		{
			ft_printf_fd(2, "exit\n");
			ft_printf_fd(2, "bash: exit: %s: ", args[1]);
			ft_printf_fd(2, "numeric argument required\n", args[1]);
			exit(255);
		}
		else if (ft_arraylen(args) > 2)
		{
			ft_printf_fd(2, "minishell: exit: too many arguments\n");
			*exit_code = 1;
			return (1);
		}
		ft_printf_fd(2, "exit\n");
		exit(ft_atoi(args[1]));
	}
	ft_printf_fd(2, "exit\n");
	exit(*exit_code);
}
