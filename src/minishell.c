/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 23:14:27 by junghwle          #+#    #+#             */
/*   Updated: 2023/12/18 22:59:16 by junghwle         ###   ########.fr       */
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

static char	**init_envp(char **envp)
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

static char	**init_export(char **envp)
{
	char	**_export;
	char	*tmp;
	int		i;

	_export = init_envp(envp);
	if (_export == NULL)
		return (NULL);
	i = 0;
	while (_export[i] != NULL)
	{
		tmp = (char *)ft_calloc((ft_strlen(_export[i]) + 14), sizeof(char));
		if (tmp == NULL)
			return (free_envp(_export), NULL);
		ft_strlcpy(tmp, "declare -x ", 12);
		ft_strlcpy(&tmp[11], _export[i], \
					(int)(ft_strchr(_export[i], '=') - _export[i] + 2));
		tmp[ft_strlen(tmp)] = '"';
		ft_strlcat(tmp, ft_strchr(_export[i], '=') + 1, \
						ft_strlen(_export[i]) + 14);
		tmp[ft_strlen(_export[i]) + 12] = '"';
		free(_export[i]);
		_export[i++] = tmp;
	}
	return (_export);
}

int	free_minishell(t_minishell shell)
{
	int	exit_code;

	exit_code = shell.exit_code;
	if (shell.cmnd_list != NULL)
		free_cmnd_list(&shell.cmnd_list);
	free_envp(shell._envp);
	free_envp(shell._export);
	free(shell.home);
	return (exit_code);
}

t_minishell	*init_minishell(int argc, char **argv, char **envp, \
								t_minishell *shell)
{
	(void)argc;
	(void)argv;
	set_default_minishell_signal();
	shell->cmnd_list = NULL;
	shell->_envp = init_envp(envp);
	shell->_export = init_export(envp);
	shell->home = search_env_value("HOME", envp, 0);
	shell->exit_code = 0;
	if (shell->_envp == NULL || shell->_export == NULL || \
		shell->home == NULL)
		return (free_minishell(*shell), NULL);
	if (update_shlvl(shell, envp) == ERROR)
		return (free_minishell(*shell), NULL);
	return (shell);
}
