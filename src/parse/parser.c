/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:03:32 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/10 02:45:24 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

t_list	*remove_blanks(t_list *token_list)
{
	t_list		*new_token_list;
	t_list_node	*cur_node;
	t_token		*cur_token;
	t_token		*new_token;

	new_token_list = list_init();
	if (new_token_list == NULL)
		return (list_clear(token_list, free_token), NULL);
	cur_node = token_list->header;
	while (cur_node != NULL)
	{
		cur_token = (t_token *)cur_node->content;
		if (cur_token->type != BK)
		{
			new_token = create_token(cur_token->type, \
						(void *)ft_strdup((char *)cur_token->content));
			if (new_token == NULL)
				return (list_clear(new_token_list, free_token), \
						list_clear(token_list, free_token), NULL);
			list_append(new_token_list, (void *)new_token);
		}
		cur_node = cur_node->next;
	}
	return (list_clear(token_list, free_token), new_token_list);
}

t_list	*parser(t_list *token_list, char **envp, int *exit_code)
{
	t_list	*parse_list;

	token_list = join_arguments(token_list);
	if (token_list == NULL)
		return (NULL);
	token_list = join_env_var_arguments(token_list);
	if (token_list == NULL)
		return (NULL);
	token_list = join_redirections(token_list);
	if (token_list == NULL)
		return (NULL);
	token_list = remove_blanks(token_list);
	if (token_list == NULL)
		return (NULL);
	token_list = check_token_error(token_list, envp, exit_code);
	if (token_list == NULL)
		return (NULL);
	parse_list = token_list;
	return (parse_list);
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

arg: word , 'word' , "word" , 'word{blank}' , "word{blank}" , 'word{blank}arg' ,
	 "word{blank}arg" , $arg , '$arg' , "$arg", $"arg", $'arg', 
	 < arg, > arg, << arg, >> arg
| : arg | arg
*/
