/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:06:07 by junghwle          #+#    #+#             */
/*   Updated: 2023/05/12 12:21:21 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	ssize;
	size_t	i;

	i = 0;
	ssize = ft_strlen(s);
	while (i <= ssize)
	{
		if (s[ssize - i] == (char)c)
			return (&((char *)s)[ssize - i]);
		i++;
	}
	return (NULL);
}
