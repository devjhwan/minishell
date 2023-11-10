/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unexpected_token_err.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 22:40:25 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/10 00:17:29 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "err_msg.h"

void	print_unexpected_token_err(char *next_token)
{
	write(STDERR_FILENO, "minishell: ", 11);
	write(STDERR_FILENO, "syntax error near unexpected token \'", 36);
	write(STDERR_FILENO, next_token, ft_strlen(next_token));
	write(STDERR_FILENO, "\'\n", 2);
}
