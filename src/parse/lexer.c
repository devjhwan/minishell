/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:03:40 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/30 13:01:03 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

static t_token	*insert_blank(t_list *token_list, char *line, int *i)
{
	t_token	*new_token;
	int		j;

	j = *i;
	while (ft_isspace(line[j]))
		j++;
	new_token = create_token(BK, ft_substr(line, *i, j - *i));
	if (new_token == NULL)
		return (NULL);
	*i = j;
	if (list_append(token_list, (void *)new_token) == NULL)
		return (free_token((void *)new_token), NULL);
	return (new_token);
}

#include <stdio.h>

static t_token	*insert_metacharacter(t_list *token_list, char *line, int *i)
{
	t_token	*new_token;

	if ((line[*i] == '<' && line[*i + 1] == '<') || \
		(line[*i] == '>' && line[*i + 1] == '>'))
	{
		new_token = create_token(RD, ft_substr(line, *i, 2));
		(*i) += 2;
	}
	else
	{
		new_token = create_token(ismetacharacter(line[*i]), \
									ft_substr(line, *i, 1));
		(*i) += 1;
	}
	if (new_token == NULL)
		return (NULL);
	if (list_append(token_list, (void *)new_token) == NULL)
		return (free_token((void *)new_token), NULL);
	return (new_token);
}

static t_token	*insert_word(t_list *token_list, char *line, int *i)
{
	t_token	*new_token;
	int		j;

	j = *i;
	while (!ft_isspace(line[j]) && !ismetacharacter(line[j]) && \
			line[j] != '\0')
		j++;
	new_token = create_token(WD, ft_substr(line, *i, j - *i));
	if (new_token == NULL)
		return (NULL);
	*i = j;
	if (list_append(token_list, (void *)new_token) == NULL)
		return (free_token((void *)new_token), NULL);
	return (new_token);
}

t_list	*lexer(char *line)
{
	t_token	*ret;
	t_list	*token_list;
	int		i;

	token_list = list_init();
	if (token_list == NULL)
		return (NULL);
	i = 0;
	while (line[i] != '\0')
	{
		if (ft_isspace(line[i]))
			ret = insert_blank(token_list, line, &i);
		else if (ismetacharacter(line[i]))
			ret = insert_metacharacter(token_list, line, &i);
		else
			ret = insert_word(token_list, line, &i);
		if (ret == NULL)
			return (list_clear(token_list, free_token), NULL);
	}
	return (token_list);
}

/*
metacharacters: <, >, <<, >>, |, (, ), ', ", $, ' ', \t, \n
	redirection: <, >, <<, >>
	control_operator: |, (, )
	env_var: $
	single_quote: '
	double_quote: "
	blank: ' ', \t, \n

word: sequence of characters
*/
