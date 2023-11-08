/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_content.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 02:28:01 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/08 02:32:34 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*join_content(char *new_content, char *cur_content)
{
	char	*str;

	if (new_content == NULL || cur_content == NULL)
		return (free(new_content), NULL);
	str = ft_strjoin(new_content, cur_content);
	free(new_content);
	if (str == NULL)
		return (NULL);
	return (str);
}
