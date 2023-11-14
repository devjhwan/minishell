// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   tester.c                                           :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/11/07 19:25:16 by jmarinel          #+#    #+#             */
// /*   Updated: 2023/11/14 01:15:06 by junghwle         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "pipe.h"

// int	main(int argc, char **argv, char **envp)
// {
// 	t_fdp	fdp;

// 	fdp = ft_init_fdp(&fdp, argc, argv);
// 	if (fdp.io[0] < 0 || fdp.io[1] < 0)
// 		return (ft_close_fds(&fdp), ft_error(ERR_PERR, 1, NULL));
// 	if (ft_mult_pipes(&fdp, cmds, envp, 0) < 0)
// 		return (ft_error(ERR_PERR, 10, NULL));
// 	if (cmnd_cnt == 1)
		

// 	return(0);
// }
// /*
// 	cmds = ft_init_cmd(&fdp, argv, envp, 0);
// 	if (!cmds)
// 		return (ft_error(ERR_CNF, 1, NULL));
// 	if (ft_mult_pipes(&fdp, cmds, envp, 0) < 0)
// 		return (ft_error(ERR_PERR, 10, NULL));
// 	fdp.i = 0;
// 	while (fdp.i < fdp.cnt)
// 	{
// 		waitpid(fdp.pid[fdp.i], &fdp.stat, 0);
// 		fdp.i++;
// 	}
// 	ft_close_fds(&fdp);
// 	ft_freep(cmds);
// 	return (WEXITSTATUS(fdp.stat));
// }
//  */