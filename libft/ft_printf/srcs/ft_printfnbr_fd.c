/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfnbr_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 20:35:53 by jmarinel          #+#    #+#             */
/*   Updated: 2023/12/04 19:29:29 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printnbr_fd(int n, int fd)
{
	char	*num;
	int		writed;

	num = ft_itoa(n);
	if (!num)
		return (-1);
	writed = ft_printstr_fd(num, fd);
	free(num);
	return (writed);
}

int	ft_printunnbr_fd(unsigned int num, int test, int fd)
{
	int	i;

	i = 0;
	if (num >= 10 && test != -1 && i != -1)
	{
		test = ft_printunnbr_fd(num / 10, test, fd);
		i = ft_test_write_fd(test, i);
		if (i == -1)
			return (i);
		test = ft_printunnbr_fd(num % 10, test, fd);
		i = ft_test_write_fd(test, i);
		if (i == -1)
			return (i);
	}
	else
	{
		test = ft_printchar_fd(num + '0', fd);
		i = ft_test_write_fd(test, i);
	}
	return (i);
}
