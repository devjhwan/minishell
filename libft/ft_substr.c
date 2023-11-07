/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 20:08:09 by junghwle          #+#    #+#             */
/*   Updated: 2023/05/31 12:10:00 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;
	size_t	size;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len < start)
		return (ft_strdup(""));
	else if (start + len > s_len)
		size = s_len - start;
	else
		size = len;
	substr = (char *)malloc(sizeof(char) * (size + 1));
	if (substr == NULL)
		return (NULL);
	ft_strlcpy(substr, s + start, size + 1);
	return (substr);
}
