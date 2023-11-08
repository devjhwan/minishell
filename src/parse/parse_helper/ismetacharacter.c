/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ismetacharacter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:46:03 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/08 16:10:24 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	ismetacharacter(char ch)
{
	if (ch == '<' || ch == '>')
		return (RD);
	else if (ch == '|')
		return (PIPE);
	else if (ch == '$')
		return (E_VAR);
	else if (ch == '\'')
		return (SQ);
	else if (ch == '\"')
		return (DQ);
	else
		return (0);
}
