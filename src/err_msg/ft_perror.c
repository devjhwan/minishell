/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 22:32:11 by junghwle          #+#    #+#             */
/*   Updated: 2023/12/04 19:53:04 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "err_msg.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

void	ft_perror(int errtype, ...)
{
	va_list	ap;
	char	*errstr;

	va_start(ap, errtype);
	if (errtype == UNEXPECTED_TOKEN)
		errstr = "minishell: syntax error near unexpected token \'%s\'\n";
	else if (errtype == AMBIGUOUS_REDIRECT)
		errstr = "minishell: %s: ambiguous redirect\n";
	else if (errtype == EXPORT_INVALID_IDENTIFIER)
		errstr = "minishell: export: \'%s\': not a valid identifier\n";
	else
		errstr = "minishell: unkown error\n";
	if (errtype < 4)
		ft_printf_fd(STDERR_FILENO, errstr, va_arg(ap, char *));
	else
		ft_printf_fd(STDERR_FILENO, errstr);
}
