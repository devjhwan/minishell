/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinel <jmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:32:51 by jmarinel          #+#    #+#             */
/*   Updated: 2023/05/25 19:39:01 by jmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ptr_len(unsigned long long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 16;
		i++;
	}
	return (i);
}

int	ft_printptr(unsigned long long n, char *base)
{
	char			c;

	if (n / 16)
	{
		ft_printptr(n / 16, base);
	}
	c = base[n % 16];
	if (ft_putchar(c) < 0)
		return (-1);
	return (0);
}

int	ft_ptr(unsigned long long n)
{
	static char	*base_lo = "0123456789abcdef";

	if (ft_putstr("0x") < 0)
		return (-1);
	if (ft_printptr(n, base_lo) == 0)
		return (ptr_len(n) + 2);
	return (-1);
}
