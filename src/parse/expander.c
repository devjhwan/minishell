/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:03:58 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/08 03:34:02 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdlib.h>

/*Used for bonus part*/

t_tree	*expander(t_tree *parse_tree)
{
	return (parse_tree);
}

/*
$ENV, "$ENV", '$ENV', $"ENV", $'ENV', "ARG", 'ARG'
*/
