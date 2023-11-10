/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 22:32:11 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/10 00:18:33 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "err_msg.h"
#include <stdarg.h>

void	ft_perror(int errtype, ...)
{
	va_list	ap;

	va_start(ap, errtype);
	if (errtype == UNEXPECTED_TOKEN)
		print_unexpected_token_err(va_arg(ap, char *));
	else if (errtype == AMBIGUOUS_REDIRECT)
		print_ambiguous_redirect_err(va_arg(ap, char *));
	else
		print_unknown_err();
	(void)errtype;
}
