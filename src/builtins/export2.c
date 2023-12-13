/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 21:41:52 by junghwle          #+#    #+#             */
/*   Updated: 2023/12/13 15:52:41 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

static char	**concatenate_argument(char **arr, char *arg, int pos, int type)
{
	char	*tmp;
	int		len;

	len = ft_strlen(arg) + ft_strlen(arr[pos]) + 4;
	tmp = (char *)malloc(sizeof(char) * len);
	ft_strlcpy(tmp, arr[pos], len);
	if (type == 0 && tmp[ft_strlen(tmp) - 1] == '\"')
		tmp[ft_strlen(tmp) - 1] = '\0';
	else if (type == 0)
		ft_strlcat(tmp, "=\"", len);
	ft_strlcat(tmp, arg, len);
	if (type == 0)
		ft_strlcat(tmp, "\"", len);
	free(arr[pos]);
	arr[pos] = tmp;
	return (arr);
}

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
											char *content, int add_flag)
{
	char	*tmp;
	int		pos;
	int		len;

	pos = var_position(_export, var_name, 11);
	if (add_flag == 1 && pos >= 0)
		return (_export = concatenate_argument(_export, content, pos, 0), \
																	_export);
	if (pos >= 0 && content == NULL)
		return (_export);
	len = ft_strlen(var_name) + ft_strlen(content) + 16;
	tmp = (char *)malloc(sizeof(char *) * (len + 1));
	if (tmp == NULL)
		return (_export);
	ft_strlcpy(tmp, "declare -x ", len);
	ft_strlcat(tmp, var_name, len);
	if (content != NULL)
	{
		ft_strlcat(tmp, "=\"", len);
		ft_strlcat(tmp, content, len);
		ft_strlcat(tmp, "\"", len);
	}
	if (pos >= 0 && content != NULL)
		return (free(_export[pos]), _export[pos] = tmp, _export);
	return (_export = append_argument(_export, tmp), _export);
}

void	*append_to_envp(char **_envp, char *var_name, char *content, \
															int add_flag)
{
	char	*tmp;
	int		pos;
	int		len;

	pos = var_position(_envp, var_name, 0);
	if (add_flag == 1 && pos >= 0)
		return (_envp = concatenate_argument(_envp, content, pos, 1), _envp);
	if (pos >= 0 && content == NULL)
		return (_envp);
	len = ft_strlen(var_name) + ft_strlen(content) + 3;
	if (content == NULL)
		return (_envp);
	tmp = (char *)malloc(sizeof(char *) * (len + 1));
	if (tmp == NULL)
		return (_envp);
	ft_strlcpy(tmp, var_name, len);
	ft_strlcat(tmp, "=", len);
	ft_strlcat(tmp, content, len);
	if (pos >= 0)
		return (free(_envp[pos]), _envp[pos] = tmp, _envp);
	return (_envp = append_argument(_envp, tmp), _envp);
}
