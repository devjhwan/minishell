/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ui.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinel <jmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:43:59 by jmarinel          #+#    #+#             */
/*   Updated: 2023/05/24 20:33:57 by jmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ui_len(unsigned int n)
{
	int	i;

	i = 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	ft_putui(unsigned int n)
{
	unsigned int	nb;
	char			c;

	nb = (unsigned int) n;
	if (nb / 10)
	{
		if (ft_putui(nb / 10) < 0)
			return (-1);
	}
	c = nb % 10 + '0';
	if (ft_putchar(c) < 0)
		return (-1);
	return (0);
}

int	ft_ui(unsigned int num)
{
	if (num == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		return (1);
	}
	if (ft_putui(num) < 0)
		return (-1);
	return (ui_len(num));
}
