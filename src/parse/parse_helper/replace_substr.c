/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_substr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 03:14:17 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/10 04:10:30 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*strjoin_inplace(char **str1, char *str2)
{
	char	*tmp;

	tmp = ft_strjoin(*str1, str2);
	if (tmp == NULL)
		return (NULL);
	free(*str1);
	*str1 = tmp;
	return (tmp);
}

char	*replace_substr(char *str, char *substr, char *replace_str)
{
	char	*new_str;
	char	*tmp;
	char	*tmp2;
	int		len;

	tmp = ft_strnstr(str, substr, ft_strlen(str));
	if (tmp == NULL)
		return (free(str), NULL);
	len = tmp - str;
	new_str = ft_substr(str, 0, len);
	if (new_str == NULL)
		return (free(str), free(substr), free(replace_str), NULL);
	if (strjoin_inplace(&new_str, replace_str) == NULL)
		return (free(str), free(substr), free(replace_str), \
				free(new_str), NULL);
	tmp += ft_strlen(substr);
	tmp2 = ft_substr(str, tmp - str, ft_strlen(tmp));
	if (tmp2 == NULL)
		return (free(str), free(substr), free(replace_str), \
				free(new_str), NULL);
	if (strjoin_inplace(&new_str, tmp2) == NULL)
		return (free(str), free(substr), free(replace_str), \
				free(new_str), free(tmp2), NULL);
	free(tmp2);
	return (free(str), free(substr), free(replace_str), new_str);
}
