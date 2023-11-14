/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:43:05 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/14 18:56:08 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "err_msg.h"
#include <stdio.h>

static void	print_export(char **_export)
{
	int	i;

	i = 0;
	
	while (_export[i] != NULL)
		printf("%s\n", _export[i++]);
}

static char	**append_new_envvar(char **_export, char **_envp, char *arg)
{
	(void)_export;
	(void)_envp;
	(void)arg;
	if (!ft_isalpha(arg[0]))
		return (ft_perror(EXPORT_INVALID_IDENTIFIER, arg), NULL);
	return (_export);
}

char	**_export(t_minishell *shell, char **args)
{
	int		i;

	if (args == NULL || args[0] == NULL)
		print_export(shell->_export);
	else
	{
		i = 0;
		while (args[i] != NULL)
		{
			if (append_new_envvar(shell->_export, \
									shell->_envp, args[i]) == NULL)
				return (NULL);
			i++;
		}
	}
	return (shell->_export);
}
