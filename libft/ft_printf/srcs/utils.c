/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinel <jmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:41:16 by jmarinel          #+#    #+#             */
/*   Updated: 2023/05/26 12:44:31 by jmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putchar(char c)
{
	return (write (1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	ret;
	int	cnt;

	cnt = 0;
	ret = 0;
	if (s == NULL)
	{
		return (ft_putstr("(null)"));
	}
	else
	{
		while (*s)
		{
			ret = ft_putchar(*s);
			if (ret < 0)
				return (-1);
			s++;
			cnt += ret;
		}
	}
	return (cnt);
}
/* 
int main (void)
{
	int		ret;
	char	*test = NULL;
	ret = ft_putstr("\001\002\007\v\010\f\r\n");
	printf("%i", ret);
	return(0);
} */