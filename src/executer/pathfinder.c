/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinel <jmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:29:38 by jmarinel          #+#    #+#             */
/*   Updated: 2023/11/21 14:14:31 by jmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

char	**init_path(t_fdp *fdp, char **args, char **envp, int i)
{
	char	**cmds;
	char	**path;

	path = findpath(envp);
	cmds = malloc(sizeof(char *) * (fdp->cmnd_cnt + 1));
	if (!cmds)
		return (NULL);
	cmds[fdp->cmnd_cnt] = NULL;
	while (i < fdp->cmnd_cnt)
	{
		cmds[i] = setpath(path, args[0]);
		if (!args || !path)
			return (NULL);
		i++;
	}
	ft_free_array(path, ft_arraylen(path));
	return (cmds);
}

char	**findpath(char **env)
{
	int		i;
	char	**path;

	path = NULL;
	i = 0;
	while (env[i] && env[i][0] != '\0')
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			path = ft_split(env[i] + 5, ":");
			if (!path)
				return (NULL);
			return (path);
		}
		else
			i++;
	}
	return (NULL);
}

char	*setpath(char **path, const char *argv)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	i = 0;
	while (path && path[i])
	{
		tmp2 = ft_strjoin(path[i], "/");
		if (!tmp2)
			return (NULL);
		tmp = ft_strjoin(tmp2, argv);
		if (!tmp)
			return (free(tmp2), NULL);
		free(tmp2);
		if (access(tmp, X_OK) == 0)
		{
			return (tmp);
		}
		i++;
		free (tmp);
	}
	return (NULL);
}
