/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unknown_err.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 22:44:26 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/09 22:50:46 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "err_msg.h"

void	print_unknown_err(void)
{
	write(STDERR_FILENO, "Unkown Error\n", 13);
}
