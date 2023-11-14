/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:37:15 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/14 14:45:26 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

void	env(t_minishell *shell)
{
	int		i;
	char	**envp;

	i = 0;
	envp = shell->_envp;
	while (envp[i] != NULL)
		printf("%s\n", envp[i++]);
}
