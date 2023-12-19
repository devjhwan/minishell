/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:19:25 by junghwle          #+#    #+#             */
/*   Updated: 2023/12/19 01:05:40 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "minishell.h"

void	pwd(void)
{
	char	cwd[1024];

	ft_printf("%s\n", getcwd(cwd, sizeof(cwd)));
}
