/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinel <jmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:43:05 by junghwle          #+#    #+#             */
/*   Updated: 2023/12/12 13:22:04 by jmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "err_msg.h"

void	*append_to_export(char **_export, char *var_name, \
											char *content, int len);
void	*append_to_envp(char **_envp, char *var_name, char *content, int len);

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

t_minishell	*append_new_envvar(t_minishell *shell, char **_export, \
											char **_envp, char *arg)
{
	int		i;
	char	*var_name;
	char	*content;

	if (!ft_isalpha(arg[0]))
		return (ft_perror(EXPORT_INVALID_IDENTIFIER, arg), NULL);
	i = 0;
	while (arg[i] != '\0' && arg[i] != '=')
	{
		if (!ft_isalnum(arg[i]) && arg[i] != '_')
			return (ft_perror(EXPORT_INVALID_IDENTIFIER, arg), NULL);
		i++;
	}
	if (split_argument(arg, &var_name, &content) == NULL)
		return (NULL);
	_export = append_to_export(_export, var_name, content, ft_strlen(arg) + 15);
	if (_export == NULL)
		return (free(var_name), free(content), NULL);
	shell->_export = _export;
	_envp = append_to_envp(_envp, var_name, content, ft_strlen(arg) + 2);
	if (_envp == NULL)
		return (free(var_name), free(content), NULL);
	shell->_envp = _envp;
	return (free(var_name), free(content), shell);
}

void	_export(t_minishell *shell, char **args)
{
	int		i;

	i = 1;
	if (args[1] == NULL)
		while (shell->_export[i] != NULL)
			printf("%s\n", shell->_export[i++]);
	else
		while (args[i] != NULL)
			append_new_envvar(shell, shell->_export, shell->_envp, args[i++]);
}
