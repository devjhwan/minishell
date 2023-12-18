/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd2.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:40:02 by junghwle          #+#    #+#             */
/*   Updated: 2023/12/18 22:27:29 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"
#include "libft.h"
#include "err_msg.h"
#include <unistd.h>

int update_pwds(t_minishell *shell);

int	cd_up(t_minishell *shell)
{
	char	cwd[1024];
	char	*strptr;
	int		ret;

	if (getcwd(cwd, sizeof(cwd)) == NULL)
		return (-1);
	strptr = ft_strrchr(cwd, '/');
	if (strptr != cwd)
		*strptr = '\0';
	else
		strptr[1] = '\0';
	ret = chdir(cwd);
	if (update_pwds(shell) == ERROR)
		return (-1);
	return (ret);
}

int	cd_home(t_minishell *shell, char *path)
{
	char	*home_var;
	int		ret;

	home_var = search_env_value("HOME", shell->_envp, shell);
	if (home_var != NULL)
		ret = chdir(home_var);
	else if (path == NULL)
		return (free(home_var), \
			write(2, "minishell: cd: HOME not set\n", 28), -1);
	else
		ret = chdir(shell->home);
	if (update_pwds(shell) == ERROR)
		return (-1);
	return (free(home_var), ret);
}

int	cd_here(t_minishell *shell)
{
	if (update_pwds(shell) == ERROR)
		return (-1);
	return (0);
}

int	cd_back(t_minishell *shell)
{
	char	*oldpwd;
	char	cwd[1024];
	char	errmsg[1000];
	int		ret;

	oldpwd = search_env_value("OLDPWD", shell->_envp, shell);
	if (oldpwd[0] == '\0')
		return (free(oldpwd), write(2, "minishell: cd: OLDPWD not set\n", 30), 0);
	if (getcwd(cwd, sizeof(cwd)) == NULL)
		return (free(oldpwd), -1);
	ret = chdir(oldpwd);
	if (ret == 0 && update_pwds(shell) == ERROR)
		return (-1);
	if (ret == -1)
	{
		ft_strlcpy(errmsg, "minishell: cd: ", 1000);
		ft_strlcat(errmsg, oldpwd, 1000);
		return (perror(errmsg), free(oldpwd), 1);
	}
	else
		return (ft_printf("%s\n", oldpwd), free(oldpwd), 0);
}

int	cd_dir(t_minishell *shell, char *path)
{
	if (chdir(path) == -1)
		return (-1);
	if (update_pwds(shell) == ERROR)
		return (-1);
	return (0);
}
