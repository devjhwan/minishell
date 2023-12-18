/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinel <jmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 19:23:09 by jmarinel          #+#    #+#             */
/*   Updated: 2023/05/23 14:38:44 by jmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	ret;

	ret = 0;
	while (*s)
	{
		ret += ft_putchar_fd(*s, fd);
		s++;
	}
	if (ret < 0)
		return (-1);
	return (ret);
}
