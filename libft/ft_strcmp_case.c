/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_case.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:59:42 by jmarinel          #+#    #+#             */
/*   Updated: 2023/12/19 01:43:47 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strcmp_upcase(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && ft_toupper(s2[i]))
		i++;
	return (s2[i] - ft_toupper(s2[i]));
}

int	ft_strcmp_case(const char *s1, const char *s2, int flag)
{
	if (flag)
	{
		if (ft_strcmp(s1, s2) == 0)
			return (0);
		else if (ft_strcmp_upcase(s1, s2) == 0)
			return (0);
		else
			return (1);
	}
	else
		return (ft_strcmp(s1, s2));
}
