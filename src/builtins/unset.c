/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinel <jmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:20:34 by jmarinel          #+#    #+#             */
/*   Updated: 2023/12/12 18:30:31 by jmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "err_msg.h"

static int	is_valid(char *arg)
{
	int	i;

	if (!ft_isalpha(arg[0]))
		return (1);
	i = 0;
	while (arg[i] != '\0' && arg[i] != '=')
	{
		if (!ft_isalnum(arg[i]) && arg[i] != '_')
			return (1);
		i++;
	}
	return (0);
}

static void	unset_export(char **_export, char *var)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (_export[i])
	{
		if (!ft_strncmp(var, _export[i] + 11, ft_strlen(var)))
		{
			tmp = _export[i];
			while (_export[i])
			{
				_export[i] = _export[i + 1];
				i++;
			}
			free (tmp);
		}
		if (_export[i])
			i++;
	}
}

static void	unset_envp(char **_envp, char *var)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (_envp[i])
	{
		if (!ft_strncmp(var, _envp[i], ft_strlen(var)))
		{
			tmp = _envp[i];
			while (_envp[i])
			{
				_envp[i] = _envp[i + 1];
				i++;
			}
			free (tmp);
		}
		if (_envp[i])
			i++;
	}
}

int	_unset(char **args, char **_envp, char **_export)
{
	int		i;
	char	*var;

	(void)_export;
	var = NULL;
	i = 1;
	while (args[i])
	{
		if (is_valid(args[i]))
		{
			ft_printf_fd(2, "minishell: unset: ");
			ft_printf_fd(2, "`%s': not a valid identifier\n", args[i]);
			return (1);
		}
		var = ft_strjoin(args[i], "=");
		if (!var)
			return (1);
		unset_envp(_envp, var);
		unset_export(_export, var);
		i++;
		free (var);
	}
	return (0);
}
