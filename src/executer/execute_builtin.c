/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:34:04 by junghwle          #+#    #+#             */
/*   Updated: 2023/12/19 11:14:49 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

static int	check_builtin2(t_cmnd *cmnd_list)
{
	if (cmnd_list->args && cmnd_list->args[0])
	{
		if (ft_strcmp_case(cmnd_list->args[0], "echo", 0) == 0)
			return (1);
		else if (ft_strcmp_case(cmnd_list->args[0], "cd", 0) == 0)
			return (1);
		else if (ft_strcmp_case(cmnd_list->args[0], "pwd", 0) == 0)
			return (1);
		else if (ft_strcmp_case(cmnd_list->args[0], "env", 0) == 0)
			return (1);
	}
	return (0);
}

int	check_builtin(t_cmnd *cmnd_list, char **env)
{
	char	**arg;

	arg = findpath(env);
	if (arg == NULL)
		return (check_builtin2(cmnd_list));
	ft_free_array(arg);
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
	int	exit_code;

	exit_code = 0;
	if (cmnd_list && cmnd_list->args && cmnd_list->args[0])
	{
		if (ft_strcmp_case(cmnd_list->args[0], "env", 1) == 0)
			env(shell);
		else if (ft_strcmp_case(cmnd_list->args[0], "echo", 1) == 0)
			exit_code = (echo(cmnd_list->args));
		else if (ft_strcmp_case(cmnd_list->args[0], "unset", 0) == 0)
			exit_code = (_unset(cmnd_list->args, shell->_envp, shell->_export));
		else if (ft_strcmp_case(cmnd_list->args[0], "exit", 0) == 0)
			exit_code = (exit_sh(cmnd_list->args, &shell->exit_code));
		else if (ft_strcmp_case(cmnd_list->args[0], "cd", 1) == 0)
			exit_code = (cd(shell, cmnd_list->args[1]));
		else if (ft_strcmp_case(cmnd_list->args[0], "export", 0) == 0)
			exit_code = _export(shell, cmnd_list->args);
		else if (ft_strcmp_case(cmnd_list->args[0], "pwd", 1) == 0)
			pwd();
	}
	shell->exit_code = exit_code;
}

int	execute_builtin(t_fdp *fdp, t_cmnd *list, t_minishell *shell)
{
	if (redirect(list->redir, fdp, shell) == SUCCESS)
	{
		if (set_redir_in(fdp) == ERROR)
			return (ERROR);
		if (set_redir_out(fdp) == ERROR)
			return (ERROR);
		exec_builtin(shell, list);
		if (restore_io(fdp) == ERROR)
			return (ERROR);
	}
	else
		return (shell->exit_code = 1, ERROR);
	return (SUCCESS);
}
