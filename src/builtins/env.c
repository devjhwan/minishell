/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinel <jmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:37:15 by junghwle          #+#    #+#             */
/*   Updated: 2023/12/13 17:46:37 by jmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

void	env(t_minishell *shell)
{
	int		i;
	char	**envp;

	i = 0;
	envp = shell->_envp;
	while (envp[i] != NULL)
		ft_printf("%s\n", envp[i++]);
}
