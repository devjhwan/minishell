/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinel <jmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:19:25 by junghwle          #+#    #+#             */
/*   Updated: 2023/12/13 17:48:05 by jmarinel         ###   ########.fr       */
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
