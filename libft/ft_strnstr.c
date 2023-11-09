/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:56:24 by junghwle          #+#    #+#             */
/*   Updated: 2023/05/22 17:08:21 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*issubstr(const char *haystack, const char *needle, \
								size_t i, size_t len)
{
	size_t	j;

	j = 0;
	while (i < len && haystack[i] != '\0' && needle[j] != '\0')
	{
		if (haystack[i] != needle[j])
			return (NULL);
		(i)++;
		j++;
	}
	if (needle[j] == '\0')
		return (&haystack[i - j]);
	else
		return (NULL);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	char	*ret;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (i < len && haystack[i] != '\0')
	{
		if (haystack[i] == needle[0])
		{
			ret = (char *)issubstr(haystack, needle, i, len);
			if (ret != NULL)
				return (ret);
		}
		i++;
	}
	return (NULL);
}
