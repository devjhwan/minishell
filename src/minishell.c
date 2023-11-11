/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 23:14:27 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/11 23:39:44 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"
#include "libft.h"

static void	free_envp(char **envp)
{
	int	i;

	if (envp == NULL)
		return ;
	i = 0;
	while (envp[i] != NULL)
		free(envp[i++]);
	free(envp);
}

static char	**copy_envp(char **envp)
{
	char	**_envp;
	int		i;

	i = 0;
	while (envp[i] != NULL)
		i++;
	_envp = (char **)malloc(sizeof(char *) * (i + 1));
	if (_envp == NULL)
		return (NULL);
	i = 0;
	while (envp[i] != NULL)
	{
		_envp[i] = ft_strdup(envp[i]);
		if (_envp[i] == NULL)
			return (free_envp(_envp), NULL);
		i++;
	}
	_envp[i] = NULL;
	return (_envp);
}

static char	**copy_export(char **envp)
{
	char	**_envp;
	char	*tmp;
	int		i;

	i = 0;
	while (envp[i] != NULL)
		i++;
	_envp = (char **)malloc(sizeof(char *) * (i + 1));
	if (_envp == NULL)
		return (NULL);
	i = 0;
	while (envp[i] != NULL)
	{
		_envp[i] = ft_strdup(envp[i]);
		if (_envp[i] == NULL)
			return (free_envp(_envp), NULL);
		tmp = _envp[i];
		_envp[i] = ft_strjoin("", envp[i]);
		free(tmp);
		if (_envp[i] == NULL)
			return (free_envp(_envp), NULL);
		i++;
	}
	_envp[i] = NULL;
	return (_envp);
}

void	free_minishell(t_minishell shell)
{
	if (shell.command_list != NULL)
		list_clear(shell.command_list, free_command);
	free_envp(shell._envp);
	free_envp(shell._export);
	free(shell.home);
	free(shell.pwd);
	free(shell.oldpwd);
}

t_minishell	*init_minishell(int argc, char **argv, char **envp, \
								t_minishell *shell)
{
	(void)argc;
	(void)argv;
	set_default_minishell_signal();
	shell->command_list = NULL;
	shell->_envp = copy_envp(envp);
	shell->_export = copy_export(envp);
	shell->home = search_env_value("HOME", envp, 0);
	shell->pwd = ft_strdup("");
	shell->oldpwd = ft_strdup("");
	shell->exit_code = 0;
	if (shell->_envp == NULL || shell->_export == NULL || \
		shell->home == NULL || shell->pwd == NULL || shell->oldpwd == NULL)
		return (free_minishell(*shell), NULL);
	return (shell);
}
