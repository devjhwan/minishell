/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:03:32 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/08 03:50:51 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_tree	*parser(t_list *token_list)
{
	t_tree	*parse_tree;

	token_list = join_tokens(token_list);
	if (token_list == NULL)
		return (NULL);
	print_lexer(token_list);
	parse_tree = tree_init();
	if (parse_tree == NULL)
		return (free_token(token_list), NULL);
	(void)token_list;
	return (list_clear(token_list, free_token), parse_tree);
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
(, ) : (), (arg)
| : arg | arg, () | arg, arg | (), () | ()

'', "", () must be in pairs. Check pair.
*/
