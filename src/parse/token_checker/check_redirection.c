/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinel <jmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 23:25:51 by junghwle          #+#    #+#             */
/*   Updated: 2023/12/14 15:33:58 by jmarinel         ###   ########.fr       */
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

static int	check_env_var_argument(char	*argument, t_minishell *shell)
{
	char	*tmp;
	char	*substr;
	int		len;

	tmp = ft_strchr(argument, '$');
	len = 1;
	while (tmp[len] != '\0' && (ft_isalnum(tmp[len]) || \
			tmp[len] == '_' || tmp[len] == '?'))
		len++;
	substr = ft_substr(tmp, 1, len);
	if (substr == NULL)
		return (-1);
	tmp = search_env_value(substr, shell->_envp, shell);
	if (tmp[0] != '\0')
		return (free(substr), free(tmp), 0);
	shell->exit_code = 2;
	ft_perror2(AMBIGUOUS_REDIRECT, substr);
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

int	check_redirection(t_list_node *cur_node, t_minishell *shell)
{
	char	*argument;

	argument = (char *)((t_token *)cur_node->content)->content;
	if (check_redirection_argument(argument) == 0)
		return (0);
	if (ft_strchr(argument, '$') != NULL)
		return (check_env_var_argument(argument, shell));
	unexpected_token_error(cur_node, &shell->exit_code);
	return (1);
}
