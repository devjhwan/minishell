/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:03:32 by junghwle          #+#    #+#             */
/*   Updated: 2023/12/14 12:24:16 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

t_list	*parser(t_list *token_list, t_minishell *shell)
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
	token_list = check_token_error(token_list, shell);
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
