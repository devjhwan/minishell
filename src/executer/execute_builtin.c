/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:34:04 by junghwle          #+#    #+#             */
/*   Updated: 2023/12/04 19:30:53 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

int	check_builtin(t_cmnd *cmnd_list)
{
	if (cmnd_list->args && cmnd_list->args[0])
	{
		if (ft_strcmp_case(cmnd_list->args[0], "echo", 1) == 0)
			return (1);
		else if (ft_strcmp_case(cmnd_list->args[0], "cd", 1) == 0)
			return (1);
		else if (ft_strcmp_case(cmnd_list->args[0], "pwd", 1) == 0)
			return (1);
		else if (ft_strcmp_case(cmnd_list->args[0], "env", 1) == 0)
			return (1);
		else if (ft_strcmp_case(cmnd_list->args[0], "export", 0) == 0)
			return (1);
		else if (ft_strcmp_case(cmnd_list->args[0], "unset", 0) == 0)
			return (1);
		else if (ft_strcmp_case(cmnd_list->args[0], "exit", 0) == 0)
			return (1);
	}
	return (0);
}

void	exec_builtin(t_minishell *shell, t_cmnd *cmnd_list)
{
	if (ft_strcmp_case(cmnd_list->args[0], "env", 1) == 0)
		env(shell);
/* 	else if (ft_strcmp_case(cmnd_list->args[0], "cd", 1) == 0)
		return (cd(shell));
	else if (ft_strcmp_case(cmnd_list->args[0], "pwd", 1) == 0)
		return (pwd(shell));
	else if (ft_strcmp_case(cmnd_list->args[0], "echo", 1) == 0)
		return (echo(shell));
	else if (ft_strcmp_case(cmnd_list->args[0], "export", 0) == 0)
		return (export(shell));
	else if (ft_strcmp_case(cmnd_list->args[0], "unset", 0) == 0)
		return (unset(shell));
	else if (ft_strcmp_case(cmnd_list->args[0], "exit", 0) == 0)
		return (exit(shell)); */
}

int	execute_builtin(t_fdp *fdp, t_cmnd *list, t_minishell *shell)
{
	char	**path;

	(void)path;
	if (set_redir_in(fdp) == ERROR)
		return (ERROR);
	if (set_redir_out(fdp) == ERROR)
		return (ERROR);
	exec_builtin(shell, list);
	if (restore_io(fdp) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
