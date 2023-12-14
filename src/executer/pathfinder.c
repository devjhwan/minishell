/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinel <jmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:29:38 by jmarinel          #+#    #+#             */
/*   Updated: 2023/12/14 15:22:18 by jmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"
#include "err_msg.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int	is_regular_file(const char *path)
{
	struct stat	path_stat;

	stat(path, &path_stat);
	return (S_ISREG(path_stat.st_mode));
}

static int	check_valid_cmd(const char *argv, int *exit_code)
{
	struct stat	path_stat;

	if (argv == NULL)
		return (ERROR);
	if (argv[0] == '\0')
		return (*exit_code = 127, \
				ft_perror(COMMAND_NOT_FOUND, argv), ERROR);
	if (argv[0] == '/')
	{
		stat(argv, &path_stat);
		if (S_ISDIR(path_stat.st_mode))
			return (*exit_code = 126, \
					ft_perror(IS_A_DIRECTORY_I, argv), ERROR);
	}
	return (SUCCESS);
}

char	**findpath(char **env)
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

char	*setpath(char **path, const char *argv, int *exit_code)
{
	int		i;
	char	*tmp;

	if (check_valid_cmd(argv, exit_code) == ERROR)
		return (NULL);
	i = 0;
	tmp = (char *)malloc(sizeof(char) * 1000);
	if (tmp == NULL || argv == NULL)
		return (free(tmp), NULL);
	while (path && path[i])
	{
		ft_strlcpy(tmp, path[i++], 1000);
		ft_strlcat(tmp, "/", 1000);
		ft_strlcat(tmp, argv, 1000);
		if (access(tmp, X_OK) == 0)
			return (tmp);
	}
	free(tmp);
	if (access(argv, X_OK) == 0)
		return (ft_strdup(argv));
	if (argv[0] == '/' && !is_directory((char *)argv))
		return (*exit_code = 127, ft_perror(NO_FILE_OR_DIRECTORY, argv), NULL);
	return (*exit_code = 127, ft_perror(COMMAND_NOT_FOUND, argv), NULL);
}
