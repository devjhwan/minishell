/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd3.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:40:02 by junghwle          #+#    #+#             */
/*   Updated: 2023/12/18 23:00:26 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"
#include "libft.h"
#include "err_msg.h"
#include <unistd.h>

static int	update_pwd(t_minishell *shell)
{
	char	*arg;
	char	cwd[1024];

	arg = search_env_value("PWD", shell->_envp, shell);
	if (arg == NULL)
		return (ERROR);
	if (arg[0] == '\0')
		return (free(arg), SUCCESS);
	free(arg);
	if (getcwd(cwd, sizeof(cwd)) == NULL)
		return (ERROR);
	arg = ft_strjoin("PWD=", cwd);
	if (arg == NULL)
		return (ERROR);
	if (append_new_envvar(shell, shell->_export, shell->_envp, arg) == ERROR)
		return (free(arg), ERROR);
	return (free(arg), SUCCESS);
}

static int	update_oldpwd(t_minishell *shell)
{
	char	*arg;
	char	cwd[1024];

	arg = search_env_value("PWD", shell->_envp, shell);
	if (arg == NULL)
		return (ERROR);
	if (arg[0] != '\0')
		ft_strlcpy(cwd, arg, 1024);
	else
		if (getcwd(cwd, sizeof(cwd)) == NULL)
			return (ERROR);
	free(arg);
	arg = ft_strjoin("OLDPWD=", cwd);
	if (arg == NULL)
		return (ERROR);
	if (append_new_envvar(shell, shell->_export, shell->_envp, arg) == ERROR)
		return (free(arg), ERROR);
	return (free(arg), SUCCESS);
}

int	update_pwds(t_minishell *shell)
{
	if (update_oldpwd(shell) == ERROR || update_pwd(shell) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
