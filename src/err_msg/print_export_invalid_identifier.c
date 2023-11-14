/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_export_invalid_identifier.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:57:03 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/14 18:59:11 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "err_msg.h"

void	print_export_invalid_identifier(char *argument)
{
	write(STDERR_FILENO, "minishell: export: '", 20);
	write(STDERR_FILENO, argument, ft_strlen(argument));
	write(STDERR_FILENO, "': not a valid identifier\n", 26);
}