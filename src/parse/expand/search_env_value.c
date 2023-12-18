/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_env_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 04:11:04 by junghwle          #+#    #+#             */
/*   Updated: 2023/12/13 21:36:29 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

static char	*spetial_env(char *substr, t_minishell *shell)
{
	char	*tmp;
	char	*ret;

	if (substr[0] == '?')
	{
		tmp = ft_itoa(shell->exit_code);
		ret = ft_strjoin(tmp, &substr[1]);
		free(tmp);
		return (ret);
	}
	return (ft_strdup(""));
}

char	*search_env_value(char *substr, char **envp, t_minishell *shell)
{
	char	*env_value;
	int		i;
	int		j;
	int		len;

	env_value = NULL;
	i = 0;
	len = ft_strlen(substr);
	while (envp[i] != NULL)
	{
		if (ft_strncmp(substr, envp[i], len) == 0 && envp[i][len] == '=')
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
		env_value = spetial_env(substr, shell);
	return (env_value);
}
