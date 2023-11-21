/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_case.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinel <jmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:59:42 by jmarinel          #+#    #+#             */
/*   Updated: 2023/11/21 12:02:01 by jmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp_case(const char *s1, const char *s2, int flag)
{
	if (flag)
	{
		while (*s1 && *s2 && ft_tolower(*s1) == ft_tolower(*s2))
		{
			s1++;
			s2++;
		}
		return (ft_tolower(*s1) - ft_tolower(*s2));
	}
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char) *s1 - (unsigned char) *s2);
}
