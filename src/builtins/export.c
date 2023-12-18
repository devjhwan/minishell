/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinel <jmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:43:05 by junghwle          #+#    #+#             */
/*   Updated: 2023/12/14 15:34:14 by jmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "err_msg.h"

void	*append_to_export(char **_export, char *var_name, char *content, \
															int add_flag);
void	*append_to_envp(char **_envp, char *var_name, char *content, \
															int add_flag);

static void	*split_argument(char *arg, char **var_name, char **content)
{
	*content = NULL;
	*var_name = (char *)malloc(sizeof(char) * (ft_strlen(arg) + 1));
	if (*var_name == NULL)
		return (NULL);
	if (ft_strchr(arg, '=') != NULL)
	{
		ft_strlcpy(*var_name, arg, (size_t)(ft_strchr(arg, '=') - arg + 1));
		*content = (char *)malloc(sizeof(char) * (ft_strlen(arg) + 1));
		if (*content == NULL)
			return (free(var_name), NULL);
		ft_strlcpy(*content, ft_strchr(arg, '=') + 1, ft_strlen(arg));
	}
	else
	{
		ft_strlcpy(*var_name, arg, ft_strlen(arg) + 1);
		*content = NULL;
	}
	return (arg);
}

static int	check_varname(char *arg)
{
	int	i;

	if (!ft_isalpha(arg[0]))
		return (ERROR);
	i = 0;
	while (arg[i] != '\0' && arg[i] != '=')
	{
		if (!ft_isalnum(arg[i]) && arg[i] != '_' && \
			!(arg[i] == '+' && arg[i + 1] == '='))
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

int	append_new_envvar(t_minishell *shell, char **_export, \
											char **_envp, char *arg)
{
	int		add_flag;
	char	*var_name;
	char	*content;

	add_flag = 0;
	if (check_varname(arg) == ERROR)
		return (ft_perror2(EXPORT_INVALID_IDENTIFIER, arg), 1);
	if (split_argument(arg, &var_name, &content) == NULL)
		return (1);
	if (var_name[ft_strlen(var_name) - 1] == '+')
	{
		add_flag = 1;
		var_name[ft_strlen(var_name) - 1] = '\0';
	}
	_export = append_to_export(_export, var_name, content, add_flag);
	if (_export == NULL)
		return (free(var_name), free(content), 1);
	shell->_export = _export;
	_envp = append_to_envp(_envp, var_name, content, add_flag);
	if (_envp == NULL)
		return (free(var_name), free(content), 1);
	shell->_envp = _envp;
	return (free(var_name), free(content), 0);
}

int	_export(t_minishell *shell, char **args)
{
	int		i;
	int		ret;

	i = 1;
	ret = SUCCESS;
	if (args[1] == NULL)
		while (shell->_export[i] != NULL)
			ft_printf("%s\n", shell->_export[i++]);
	else
		while (args[i] != NULL)
			if (append_new_envvar(shell, shell->_export, \
									shell->_envp, args[i++]) == ERROR)
				ret = ERROR;
	return (ret);
}
