/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinel <jmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:37:15 by junghwle          #+#    #+#             */
/*   Updated: 2023/12/07 15:34:18 by jmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env(t_minishell *shell)
{
	int		i;
	char	**envp;

	i = 0;
	envp = shell->_envp;
	while (envp[i] != NULL)
		printf("%s\n", envp[i++]);
	//falta actualizar el SHLVL si entramos en otra minishell
}
