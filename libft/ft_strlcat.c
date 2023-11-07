/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:57:26 by junghwle          #+#    #+#             */
/*   Updated: 2023/05/22 17:08:08 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dsize;
	size_t	ssize;
	size_t	tsize;
	size_t	i;

	dsize = ft_strlen(dst);
	ssize = ft_strlen(src);
	if (dsize >= dstsize)
		tsize = dstsize + ssize;
	else
	{
		tsize = dsize + ssize;
		i = 0;
		while ((i < dstsize - dsize - 1) && (src[i] != '\0'))
		{
			dst[i + dsize] = src[i];
			i++;
		}
		dst[i + dsize] = '\0';
	}
	return (tsize);
}
