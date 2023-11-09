/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_env_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 04:11:04 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/09 18:33:39 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*search_env_value(char *substr, char **envp, int last_exit_code)
{
	char	*env_value;
	int		i;
	int		j;
	int		len;

	if (substr[0] == '?')
		return (ft_strjoin(ft_itoa(last_exit_code), &substr[1]));
	env_value = NULL;
	i = 0;
	len = ft_strlen(substr);
	while (envp[i] != NULL)
	{
		if (ft_strncmp(substr, envp[i], len) == 0)
		{
			j = 0;
			while (envp[i][j] != '\0' && envp[i][j] != '=')
				j++;
			env_value = ft_substr(envp[i], j + 1, ft_strlen(envp[i]) - j - 1);
			break ;
		}
		i++;
	}
	if (env_value == NULL)
		env_value = ft_strdup("");
	return (env_value);
}
