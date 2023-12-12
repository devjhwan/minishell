/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:20:26 by jmarinel          #+#    #+#             */
/*   Updated: 2023/12/04 19:30:36 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

int	executer(t_cmnd *cmnd_list, t_minishell *shell)
{
	t_fdp	fdp;
	int		ret;

	if (init_data(&fdp, cmnd_list, shell->_envp) == ERROR)
		return (close_fds(&fdp), free_fdp(&fdp), ERROR);
	if (cmnd_list->next == NULL && check_builtin(cmnd_list))
		ret = execute_builtin(&fdp, cmnd_list, shell);
	else
		ret = execute_pipeline(cmnd_list, &fdp, shell);
	close_fds(&fdp);
	free_fdp(&fdp);
	return (ret);
}
