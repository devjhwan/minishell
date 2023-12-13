/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:47:49 by jmarinel          #+#    #+#             */
/*   Updated: 2023/12/13 21:37:47 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "parser.h"
#include "err_msg.h"

static int	is_pathset(t_minishell *shell)
{
	char	*path;

	path = search_env_value("PATH", shell->_envp, shell);
	if (path[0] == '\0')
		return (free(path), 0);
	else
		return (free(path), 1);
}

static int	is_n(char *str)
{
	int	i;

	if (str[0] != '-')
		return (0);
	i = 1;
	while (str[i] == 'n')
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
}

int	echo(t_minishell *shell, char **args)
{
	int		i;

	if (!is_pathset(shell))
		return (ft_perror(NO_FILE_OR_DIRECTORY, args[0]), 127);
	i = 1;
	if (args[1] == NULL)
	{
		ft_printf ("\n");
		return (0);
	}
	while (args[i] && is_n(args[i]))
		i++;
	while (args[i])
	{
		ft_printf("%s", args[i]);
		if (args[i + 1] != NULL)
			ft_printf(" ");
		i++;
	}
	if (is_n(args[1]) == 0)
		ft_printf ("\n");
	return (0);
}
