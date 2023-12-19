/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:47:49 by jmarinel          #+#    #+#             */
/*   Updated: 2023/12/19 01:53:38 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "parser.h"
#include "err_msg.h"

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

int	echo(char **args)
{
	int		i;

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
