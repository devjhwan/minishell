/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinel <jmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:58:04 by jmarinel          #+#    #+#             */
/*   Updated: 2023/05/23 14:39:07 by jmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ptrd;
	unsigned char	*ptrs;

	ptrd = dst;
	ptrs = (unsigned char *)src;
	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (n > i)
	{
		ptrd[i] = ptrs[i];
		i++;
	}
	return (ptrd);
}
/*
#include <stdio.h>
int main()
{
	char *a;
	char b[6];
	a = ft_memcpy(b, "absdf", 6);
	printf("%s\n", a); 
	return 0;
}*/
