/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_substr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:11:37 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/08 17:11:54 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*append_substr(char	*dest, char	*src, unsigned int start, size_t len)
{
	char	*str_tmp1;
	char	*str_tmp2;

	if (dest == NULL)
		return (NULL);
	if (src == NULL)
		return (free(dest), NULL);
	str_tmp1 = ft_substr(src, start, len);
	if (str_tmp1 == NULL)
		return (free(dest), NULL);
	str_tmp2 = ft_strjoin(dest, str_tmp1);
	if (str_tmp2 == NULL)
		return (free(dest), free(str_tmp1), NULL);
	free(dest);
	dest = str_tmp2;
	return (dest);
}
