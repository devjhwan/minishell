/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 23:25:51 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/10 00:41:10 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include "err_msg.h"

static int	check_redirection_argument(char	*argument)
{
	if (ft_strchr(argument, '$') != NULL)
		return (1);
	else if (ft_strlen(argument) > 2)
		return (0);
	else if (argument[1] != '\0' && argument[1] != '>' && argument[1] != '<')
		return (0);
	else
		return (1);
}

static int	check_env_var_argument(char	*argument, char	**envp, int *exit_code)
{
	char	*tmp;
	char	*substr;
	int		len;
	int		i;

	tmp = ft_strchr(argument, '$');
	len = 1;
	while (tmp[len] != '\0' && (ft_isalnum(tmp[len]) || \
			tmp[len] == '_' || tmp[len] == '?'))
		len++;
	substr = ft_substr(tmp, 0, len);
	if (substr == NULL)
		return (-1);
	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(&substr[1], envp[i], len - 1) == 0 && \
				envp[i][len - 1] == '=')
			return (free(substr), 0);
		i++;
	}
	*exit_code = 2;
	ft_perror(AMBIGUOUS_REDIRECT, substr);
	return (free(substr), 1);
}

static void	unexpected_token_error(t_list_node *cur_node, int *exit_code)
{
	t_list_node	*next_node;
	t_token		*next_token;

	next_node = cur_node->next;
	if (next_node == NULL)
	{
		*exit_code = 2;
		ft_perror(UNEXPECTED_TOKEN, "newline");
	}
	else
	{
		next_token = (t_token *)cur_node->next->content;
		if (next_token->type != ARG)
		{
			*exit_code = 2;
			ft_perror(UNEXPECTED_TOKEN, (char *)next_token->content);
		}
		else
			ft_perror(UNKNWON_ERROR);
	}
}

int	check_redirection(t_list_node *cur_node, char **envp, int *exit_code)
{
	char	*argument;

	argument = (char *)((t_token *)cur_node->content)->content;
	if (check_redirection_argument(argument) == 0)
		return (0);
	if (ft_strchr(argument, '$') != NULL)
		return (check_env_var_argument(argument, envp, exit_code));
	unexpected_token_error(cur_node, exit_code);
	return (1);
}
