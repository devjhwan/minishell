/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:40:02 by junghwle          #+#    #+#             */
/*   Updated: 2023/12/18 22:36:40 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"
#include "libft.h"
#include "err_msg.h"
#include <unistd.h>

int	cd_up(t_minishell *shell);
int	cd_home(t_minishell *shell, char *path);
int	cd_here(t_minishell *shell);
int	cd_back(t_minishell *shell);
int	cd_dir(t_minishell *shell, char *path);

int	cd(t_minishell *shell, char *path)
{
	int		ret;
	char	errmsg[1000];

	if (path != NULL && path[0] == '\0')
		return (0);
	ret = 0;
	if (path == NULL || ft_strncmp(path, "~", 2) == 0)
		ret = cd_home(shell, path);
	else if (ft_strncmp(path, "..", 3) == 0)
		ret = cd_up(shell);
	else if (ft_strncmp(path, ".", 2) == 0)
		ret = cd_here(shell);
	else if (ft_strncmp(path, "-", 2) == 0)
		ret = cd_back(shell);
	else
		ret = cd_dir(shell, path);
	ft_strlcpy(errmsg, "minishell: cd: ", 1000);
	if (path != NULL)
		ft_strlcat(errmsg, path, 1000);
	if (ret == -1)
		return (perror(errmsg), 1);
	return (ret);
}
