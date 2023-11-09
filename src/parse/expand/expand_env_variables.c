/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env_variables.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 02:41:07 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/09 04:57:07 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

static char	*substract_env_var(char *argument, int start)
{
	int		end;
	char	*substr;

	end = start + 1;
	while (argument[end] != '\0' && (ft_isalnum(argument[end]) || \
			argument[end] == '_'))
		end++;
	substr = ft_substr(argument, start, end - start);
	return (substr);
}

static char	*get_expanded_env_var(char *substr, char **envp)
{
	char	*env_value;

	env_value = NULL;
	if (ft_strncmp(substr, "$", 2) == 0)
		return (ft_strdup("$"));
	if (substr[1] == '\'' || substr[1] == '\"')
	{
		env_value = ft_strdup(substr);
		if (env_value == NULL)
			return (NULL);
		ft_strlcpy(env_value + 1, env_value + 2, ft_strlen(env_value) - 1);
	}
	else
		env_value = search_env_value(substr + 1, envp);
	return (env_value);
}

static char	*replace_env_variables(char *argument, char **envp, \
									char *substr, char *env_value)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(argument);
	while (i < len)
	{
		if (argument[i] == '$' && !(i >= 1 && argument[i - 1] == '\\'))
		{
			substr = substract_env_var(argument, i);
			if (substr == NULL)
				return (free(argument), NULL);
			env_value = get_expanded_env_var(substr, envp);
			if (env_value == NULL)
				return (free(argument), free(substr), NULL);
			argument = replace_substr(argument, substr, env_value);
			free(substr);
			free(env_value);
			if (argument == NULL)
				return (NULL);
			len = ft_strlen(argument);
		}
		i++;
	}
	return (argument);
}

char	*check_quote(char *argument)
{
	if (argument[0] == '\'')
	{
		ft_strlcpy(argument, argument + 1, ft_strlen(argument) - 1);
		return (NULL);
	}
	if (argument[0] == '\"')
		ft_strlcpy(argument, argument + 1, ft_strlen(argument) - 1);
	return (argument);
}

t_list	*expand_env_variables(t_list *parse_list, char **envp)
{
	t_list_node	*cur_node;
	t_token		*cur_token;
	char		*argument;
	char		*new_argument;

	cur_node = parse_list->header;
	while (cur_node != NULL)
	{
		cur_token = (t_token *)cur_node->content;
		argument = (char *)cur_token->content;
		if (ft_strchr(argument, '$') != NULL && check_quote(argument) != NULL)
		{
			new_argument = replace_env_variables(ft_strdup(argument), envp, \
													NULL, NULL);
			if (new_argument == NULL)
				return (list_clear(parse_list, free_token), NULL);
			free(argument);
			cur_token->content = (void *)new_argument;
		}
		cur_node = cur_node->next;
	}
	return (parse_list);
}
