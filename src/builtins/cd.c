/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:40:02 by junghwle          #+#    #+#             */
/*   Updated: 2023/12/13 16:45:02 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"
#include "libft.h"
#include "err_msg.h"
#include <unistd.h>

static int	cd_up(t_minishell *shell)
{
	char	cwd[1024];
	char	*strptr;

	if (getcwd(cwd, sizeof(cwd)) == NULL)
		return (-1);
	shell->oldpwd = ft_strdup(cwd);
	if (shell->oldpwd == NULL)
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

	home_var = search_env_value("HOME", shell->_envp, shell);
	if (home_var != NULL)
		return (chdir(home_var));
	else if (path == NULL)
		return (write(2, "minishell: cd: HOME not set\n", 28), -1);
	else
		return (chdir(shell->home));
}

static int	cd_here(t_minishell *shell)
{
	char	cwd[1024];

	free(shell->oldpwd);
	if (getcwd(cwd, sizeof(cwd)) == NULL)
		return (-1);
	shell->oldpwd = ft_strdup(cwd);
	return (0);
}

static int	cd_back(t_minishell *shell)
{
	char	*oldpwd;
	char	cwd[1024];
	int		ret;

	if (shell->oldpwd == NULL)
		return (write(2, "minishell: cd: OLDPWD not set\n", 30), -1);
	oldpwd = shell->oldpwd;
	if (getcwd(cwd, sizeof(cwd)) == NULL)
		return (-1);
	shell->oldpwd = ft_strdup(cwd);
	ret = chdir(oldpwd);
	return (free(oldpwd), ret);
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
	return (0);
}
