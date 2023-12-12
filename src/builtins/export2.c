/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinel <jmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 21:41:52 by junghwle          #+#    #+#             */
/*   Updated: 2023/12/12 12:45:58 by jmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

static char	**append_argument(char **arr, char *arg)
{
	char	**new_arr;
	int		i;
	int		len;

	len = 0;
	while (arr[len] != NULL)
		len++;
	new_arr = (char **)malloc(sizeof(char *) * (len + 2));
	if (new_arr == NULL)
		return (NULL);
	i = 0;
	while (arr[i] != NULL)
	{
		new_arr[i] = arr[i];
		i++;
	}
	new_arr[i++] = arg;
	new_arr[i++] = NULL;
	free (arr);
	return (new_arr);
}

static int	var_position(char **arr, char *var_name, int offset)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(var_name);
	while (arr[i] != NULL)
	{
		if (ft_strncmp(&arr[i][offset], var_name, len) == 0 && \
			(arr[i][len + offset] == '=' || arr[i][len + offset] == '\0'))
			return (i);
		i++;
	}
	return (-1);
}

void	*append_to_export(char **_export, char *var_name, \
											char *content, int len)
{
	char	*tmp;
	int		pos;

	tmp = (char *)malloc(sizeof(char *) * (len + 1));
	if (tmp == NULL)
		return (_export);
	ft_strlcpy(tmp, "declare -x ", len);
	ft_strlcat(tmp, var_name, len);
	if (content != NULL)
	{
		ft_strlcat(tmp, "=", len);
		ft_strlcat(tmp, "\"", len);
		ft_strlcat(tmp, content, len);
		ft_strlcat(tmp, "\"", len);
	}
	pos = var_position(_export, var_name, 11);
	if (pos >= 0)
	{
		free(_export[pos]);
		_export[pos] = tmp;
	}
	else
		_export = append_argument(_export, tmp);
	return (_export);
}

void	*append_to_envp(char **_envp, char *var_name, char *content, int len)
{
	char	*tmp;
	int		pos;

	if (content == NULL)
		return (_envp);
	tmp = (char *)malloc(sizeof(char *) * (len + 1));
	if (tmp == NULL)
		return (_envp);
	ft_strlcpy(tmp, var_name, len);
	ft_strlcat(tmp, "=", len);
	ft_strlcat(tmp, content, len);
	pos = var_position(_envp, var_name, 0);
	if (pos >= 0)
	{
		free(_envp[pos]);
		_envp[pos] = tmp;
	}
	else
		_envp = append_argument(_envp, tmp);
	return (_envp);
}
