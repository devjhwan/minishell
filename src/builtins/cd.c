/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:40:02 by junghwle          #+#    #+#             */
/*   Updated: 2023/12/18 21:03:08 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"
#include "libft.h"
#include "err_msg.h"
#include <unistd.h>

static int	cd_here(t_minishell *shell);

static int	cd_up(t_minishell *shell)
{
	char	cwd[1024];
	char	*strptr;

	if (cd_here(shell) == -1)
		return (-1);
	if (getcwd(cwd, sizeof(cwd)) == NULL)
		return (-1);
	strptr = ft_strrchr(cwd, '/');
	if (strptr != cwd)
		*strptr = '\0';
	else
		strptr[1] = '\0';
	return (chdir(cwd));
}

static int	cd_home(t_minishell *shell, char *path)
{
	char	*home_var;
	int		ret;

	if (cd_here(shell) == -1)
		return (-1);
	home_var = search_env_value("HOME", shell->_envp, shell);
	if (home_var != NULL)
		ret = chdir(home_var);
	else if (path == NULL)
		return (free(home_var), \
			write(2, "minishell: cd: HOME not set\n", 28), -1);
	else
		ret = chdir(shell->home);
	return (free(home_var), ret);
}

static int	cd_here(t_minishell *shell)
{
	char	cwd[1024];
	char	*new_dir;

	if (getcwd(cwd, sizeof(cwd)) == NULL)
		return (-1);
	new_dir = ft_strjoin("OLDPWD=", cwd);
	if (append_new_envvar(shell, shell->_export, shell->_envp, new_dir) == ERROR)
		return (free(new_dir), -1);
	return (free(new_dir), 0);
}

static int	cd_back(t_minishell *shell)
{
	char	*oldpwd;
	char	cwd[1024];
	char	errmsg[1000];
	int		ret;

	oldpwd = search_env_value("OLDPWD", shell->_envp, shell);
	if (oldpwd[0] == '\0')
		return (free(oldpwd), write(2, "minishell: cd: OLDPWD not set\n", 30), 0);
	if (cd_here(shell) == -1)
		return (free(oldpwd), -1);
	if (getcwd(cwd, sizeof(cwd)) == NULL)
		return (free(oldpwd), -1);
	ret = chdir(oldpwd);
	if (ret == -1)
	{
		ft_strlcpy(errmsg, "minishell: cd: ", 1000);
		ft_strlcat(errmsg, oldpwd, 1000);
		return (perror(errmsg), free(oldpwd), 1);
	}
	else
		return (ft_printf("%s\n", oldpwd), free(oldpwd), 0);
}

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
		ret = chdir(path);
	ft_strlcpy(errmsg, "minishell: cd: ", 1000);
	if (path != NULL)
		ft_strlcat(errmsg, path, 1000);
	if (ret == -1)
		return (perror(errmsg), 1);
	return (ret);
}
