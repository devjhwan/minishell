/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:23:47 by jmarinel          #+#    #+#             */
/*   Updated: 2023/12/19 11:42:34 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_num(char *arg)
{
	int	i;

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
