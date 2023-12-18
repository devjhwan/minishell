/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinel <jmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:49:22 by jmarinel          #+#    #+#             */
/*   Updated: 2023/05/25 12:32:44 by jmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_parse(va_list args, const char *s)
{
	int	ret;
	int	cnt;

	ret = 0;
	cnt = 0;
	while (*s)
	{
		if (*s == '%')
		{
			ret = ft_search(args, *(++s));
			if (ret < 0)
				return (-1);
			cnt += ret;
			s++;
		}
		else
		{
			ret = ft_putchar(*(s++));
			if (ret < 0)
				return (-1);
			cnt += ret;
		}
	}
	return (cnt);
}
