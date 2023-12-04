/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:29:38 by jmarinel          #+#    #+#             */
/*   Updated: 2023/12/04 19:27:26 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

static char	**findpath(char **env);
static char	*setpath(char **path, const char *argv);

char	**init_path(t_fdp *fdp, t_cmnd *list, char **envp, int i)
{
	char	**cmds;
	char	**path;

	path = findpath(envp);
	if (path == NULL)
		return (NULL);
	cmds = malloc(sizeof(char *) * (fdp->cmnd_cnt + 1));
	if (!cmds)
		return (ft_free_array(path), NULL);
	while (list)
	{
		cmds[i] = setpath(path, list->args[0]);
		if (cmds[i] == NULL)
			return (ft_free_array(path), ft_free_array(cmds), NULL);
		i++;
		list = list->next;
	}
	cmds[fdp->cmnd_cnt] = NULL;
	return (ft_free_array(path), cmds);
}

static char	**findpath(char **env)
{
	int		i;

	i = 0;
	while (env[i] && env[i][0] != '\0')
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (ft_split(env[i] + 5, ":"));
		i++;
	}
	return (NULL);
}

static char	*setpath(char **path, const char *argv)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = (char *)malloc(sizeof(char) * 1000);
	if (tmp == NULL)
		return (NULL);
	while (path && path[i])
	{
		ft_strlcpy(tmp, path[i], 1000);
		ft_strlcat(tmp, "/", 1000);
		ft_strlcat(tmp, argv, 1000);
		if (access(tmp, X_OK) == 0)
			return (tmp);
		i++;
	}
	ft_strlcpy(tmp, argv, 1000);
	if (access(tmp, X_OK) == 0)
		return (tmp);
	return (free(tmp), NULL);
}
