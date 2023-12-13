/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinel <jmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:47:49 by jmarinel          #+#    #+#             */
/*   Updated: 2023/12/13 14:07:21 by jmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

static int is_n(char *str)
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

int echo(char **args)
{
	int	i;

	i = 1;
	if (args[1] == NULL)
	{
		printf ("\n");
		return (0);
	}
	while (args[i] && is_n(args[i]))
		i++;
	while (args[i])
		printf("%s ", args[i++]);
	if (is_n(args[1]) == 0)
		printf ("\n");
	return (0);
}