/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 03:19:00 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/10 04:04:12 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

static char	get_redirection_type(char *red_argument)
{
	if (ft_strncmp(red_argument, "<<", 2) == 0)
		return (DIN);
	else if (ft_strncmp(red_argument, ">>", 2) == 0)
		return (DOUT);
	else if (ft_strncmp(red_argument, "<", 1) == 0)
		return (IN);
	else if (ft_strncmp(red_argument, ">", 1) == 0)
		return (OUT);
	else
		return (UNKNOWN);
}

static char	*get_redirection_file(char *red_argument)
{
	int	i;

	i = 0;
	while (red_argument[i] == '<' || red_argument[i] == '>' || \
			red_argument[i] == ' ')
		i++;
	return (ft_strdup(&red_argument[i]));
}

t_redirection	*get_redirection(t_command *command)
{
	t_redirection	*redirection;
	char			*red_argument;

	red_argument = (char *)list_pop(command->redirection);
	if (red_argument == NULL)
		return (NULL);
	redirection = (t_redirection *)malloc(sizeof(t_redirection));
	if (redirection == NULL)
		return (free(red_argument), NULL);
	redirection->type = get_redirection_type(red_argument);
	redirection->file = get_redirection_file(red_argument);
	if (redirection->file == NULL)
		return (free(redirection), free(red_argument), NULL);
	return (free(red_argument), redirection);
}

void	free_redirection(t_redirection *redirection)
{
	free(redirection->file);
	free(redirection);
}
