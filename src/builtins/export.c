/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:43:05 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/14 15:35:49 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

static void	print_export(char **_export)
{
	int	i;

	i = 0;
	
	while (_export[i] != NULL)
		printf("%s\n", _export[i++]);
}

static char	**append_export(char **_export, char *arg)
{
	(void)_export;
	(void)arg;
	return (_export);
}

char	**_export(t_minishell *shell, char **args)
{
	int		i;
	char	**_export;

	_export = shell->_export;
	if (args[0] == NULL)
		print_export(_export);
	else
	{
		i = 0;
		while (args[i] != NULL)
		{
			if (append_export(_export, args[i]) == NULL)
				return (NULL);
			i++;
		}
	}
	return (_export);
}
