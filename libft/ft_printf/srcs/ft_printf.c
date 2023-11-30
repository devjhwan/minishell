/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinel <jmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:28:05 by jmarinel          #+#    #+#             */
/*   Updated: 2023/06/01 13:52:28 by jmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_search(va_list args, char s)
{
	int		ret;

	ret = 0;
	if (s == 'c')
		ret = ft_putchar(va_arg(args, int));
	else if (s == 's')
		ret = ft_putstr(va_arg(args, char *));
	else if (s == 'p')
		ret = ft_ptr(va_arg(args, unsigned long long));
	else if (s == 'd' || s == 'i')
		ret = ft_print_integuer(va_arg(args, int));
	else if (s == 'u')
		ret = ft_ui(va_arg(args, unsigned int));
	else if (s == 'x' || s == 'X')
		ret = ft_hexnum(va_arg(args, unsigned int), s);
	else
		ret = ft_putchar(s);
	if (ret < 0)
		return (-1);
	return (ret);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		ret;

	va_start(args, s);
	ret = ft_parse(args, s);
	if (ret < 0)
		return (-1);
	va_end(args);
	return (ret);
}
