/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinel <jmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:23:47 by jmarinel          #+#    #+#             */
/*   Updated: 2023/12/13 15:50:56 by jmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_num(char *arg)
{
	int	i;
	int	block;

	block = 0;
	i = 0;
	while (ft_isspace(arg[i]))
		i++;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	if (arg[i])
	{
		while (arg[i] >= '0' && arg[i] <= '9')
			i++;
		while (arg[i] && ft_isspace(arg[i]))
			i++;
	}
	if (arg[i])
		return (1);
	return (0);
}
/* 	if (arg[i] == '\0')
		return (1); */

/* 	if (!(arg[i] >= '0' && arg[i] <= '9'))
		return (1); */