/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env_variables.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 02:41:07 by junghwle          #+#    #+#             */
/*   Updated: 2023/12/13 17:09:29 by junghwle         ###   ########.fr       */
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
			argument[end] == '_' || argument[end] == '?'))
		end++;
	substr = ft_substr(argument, start, end - start);
	return (substr);
}

static char	*get_expanded_env_var(char *substr, t_minishell *shell)
{
	char	*env_value;

	env_value = NULL;
	if (ft_strncmp(substr, "$", 2) == 0)
		return (ft_strdup("$"));
	if (isquote(substr[1]))
	{
		env_value = ft_strdup(substr);
		if (env_value == NULL)
			return (NULL);
		ft_strlcpy(env_value + 1, env_value + 2, ft_strlen(env_value) - 1);
	}
	else
		env_value = search_env_value(substr + 1, shell->_envp, shell);
	return (env_value);
}

static char	*replace_env_variables(char *argument, t_minishell *shell)
{
	int		i;
	int		len;
	char	*substr;
	char	*env_value;

	i = 0;
	len = ft_strlen(argument);
	while (i < len)
	{
		if (argument[i] == '$' && !(i >= 1 && argument[i - 1] == '\\'))
		{
			substr = substract_env_var(argument, i);
			if (substr == NULL)
				return (free(argument), NULL);
			env_value = get_expanded_env_var(substr, shell);
			if (env_value == NULL)
				return (free(argument), free(substr), NULL);
			argument = replace_substr(argument, substr, env_value);
			if (argument == NULL)
				return (NULL);
			len = ft_strlen(argument);
		}
		i++;
	}
	return (argument);
}

int	check_quote(char *argument)
{
	char	*squote;
	char	*dquote;

	squote = ft_strchr(argument, '\'');
	dquote = ft_strchr(argument, '\"');
	if ((dquote == NULL && squote != NULL) || \
		(dquote != NULL && squote != NULL && squote < dquote))
		return (1);
	else
		return (0);
}

t_list	*expand_env_variables(t_list *parse_list, t_minishell *shell)
{
	t_list_node	*cur_node;
	t_token		*cur_token;
	char		*argument;
	char		*new_argument;

	cur_node = parse_list->header;
	while (cur_node != NULL)
	{
		new_argument = NULL;
		cur_token = (t_token *)cur_node->content;
		argument = (char *)cur_token->content;
		if (ft_strchr(argument, '$') != NULL && !check_quote(argument) && \
			ft_strncmp(argument, "<<", 2) != 0)
		{
			new_argument = replace_env_variables(ft_strdup(argument), shell);
			if (new_argument == NULL)
				return (list_clear(parse_list, free_token), NULL);
			free(cur_token->content);
			cur_token->content = (void *)new_argument;
		}
		cur_node = cur_node->next;
	}
	return (parse_list);
}
