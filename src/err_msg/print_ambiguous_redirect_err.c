/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ambiguous_redirect_err.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 00:12:42 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/30 16:08:44 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "err_msg.h"

void	print_ambiguous_redirect_err(char *env_var)
{
	write(STDERR_FILENO, "minishell: ", 11);
	write(STDERR_FILENO, env_var, ft_strlen(env_var));
	write(STDERR_FILENO, ": ambiguous redirect\n", 21);
}
