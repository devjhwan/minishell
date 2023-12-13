/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 23:14:27 by junghwle          #+#    #+#             */
/*   Updated: 2023/12/13 13:33:49 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"
#include "libft.h"
#include "err_msg.h"

void	unset_shlvl(t_minishell *shell)
{
	char	**args;

	args = ft_split("unset SHLVL", " ");
	if (args != NULL)
	{
		_unset(args, shell->_envp, shell->_export);
		free(args[0]);
		free(args[1]);
		free(args);
	}
}

int	update_shlvl(t_minishell *shell, char **envp)
{
	char	*env_value;
	char	*arg;
	char	*tmp;
	int		value;

	value = 1;
	env_value = search_env_value("SHLVL", envp, shell);
	if (env_value != NULL)
		value = ft_atoi(env_value) + 1;
	if (value == 1000)
		return (free(env_value), unset_shlvl(shell), SUCCESS);
	if (value < 0)
		value = 0;
	tmp = ft_itoa(value);
	if (tmp == NULL)
		return (free(env_value), ERROR);
	if (value > 1000)
	{
		ft_perror(HIGH_SHELL_LEVEL, tmp);
		ft_strlcpy(tmp, "1", 2);
	}
	arg = ft_strjoin("SHLVL=", tmp);
	if (arg != NULL)
		append_new_envvar(shell, shell->_export, shell->_envp, arg);
	return (free(env_value), free(tmp), free(arg), SUCCESS);
}
