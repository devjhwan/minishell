/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 20:54:21 by junghwle          #+#    #+#             */
/*   Updated: 2023/08/26 10:05:56 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char *set)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (ft_strchr(set, s[i++]) == NULL)
		{
			count++;
			while (ft_strchr(set, s[i]) == NULL && s[i] != '\0')
				i++;
		}
	}
	return (count);
}

static size_t	word_len(char const *s, char *set)
{
	size_t	len;

	len = 0;
	while (ft_strchr(set, s[len]) == NULL && s[len] != '\0')
		len++;
	return (len);
}

static void	*free_2d(char **ret, size_t i)
{
	while (i > 0)
		free(ret[--i]);
	free(ret);
	return (NULL);
}

static char	**fill_word(char **ret, char const *s, char *set, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	wlen;

	i = 0;
	j = 0;
	while (i < len)
	{
		while (ft_strchr(set, s[j]) != NULL && s[j] != '\0')
			j++;
		wlen = word_len(&s[j], set);
		ret[i] = (char *)malloc(sizeof(char) * (wlen + 1));
		if (ret[i] == NULL)
			return (free_2d(ret, i));
		ft_strlcpy(ret[i], &s[j], wlen + 1);
		i++;
		j += wlen;
	}
	ret[i] = NULL;
	return (ret);
}

char	**ft_split(char const *s, char *set)
{
	size_t	len;
	char	**ret;

	if (s == NULL)
		return (NULL);
	len = count_words(s, set);
	ret = (char **)malloc(sizeof(char *) * (len + 1));
	if (ret == NULL)
		return (NULL);
	return (fill_word(ret, s, set, len));
}
