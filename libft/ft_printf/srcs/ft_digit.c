/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinel <jmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:41:03 by jmarinel          #+#    #+#             */
/*   Updated: 2023/05/25 13:56:36 by jmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	nbr_len(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	unsigned int	nb;
	char			c;

	if (n < 0)
	{
		nb = (unsigned int) -n;
		if (ft_putchar('-') < 0)
			return (-1);
	}
	else
		nb = (unsigned int) n;
	if (nb / 10)
	{
		if (ft_putnbr(nb / 10) < 0)
			return (-1);
	}
	c = nb % 10 + '0';
	if (ft_putchar(c) < 0)
		return (-1);
	return (0);
}

int	ft_print_integuer(int num)
{
	if (num == 0)
	{
		if (write(1, "0", 1) < 0)
			return (-1);
		return (1);
	}
	if (ft_putnbr(num) == 0)
		return (nbr_len(num));
	return (-1);
}
