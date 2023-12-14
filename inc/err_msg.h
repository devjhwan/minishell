/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_msg.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinel <jmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 22:35:37 by junghwle          #+#    #+#             */
/*   Updated: 2023/12/14 13:47:12 by jmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERR_MSG_H
# define ERR_MSG_H

# include "libft.h"
# include <unistd.h>

# define UNEXPECTED_TOKEN 0
# define AMBIGUOUS_REDIRECT 1
# define EXPORT_INVALID_IDENTIFIER 2
# define NO_FILE_OR_DIRECTORY 3
# define COMMAND_NOT_FOUND 4
# define PERMISSION_DENIED 5
# define HIGH_SHELL_LEVEL 6
# define NUMERIC_ARGUMENT 7
# define IS_A_DIRECTORY 8
# define IS_A_DIRECTORY_I 9
# define TOO_MANY_ARGS 20
# define UNKNWON_ERROR 127

void	ft_perror(int errtype, ...);
void	print_unexpected_token_err(char *next_token);
void	print_ambiguous_redirect_err(char *env_var);
void	print_unknown_err(void);
void	print_export_invalid_identifier(char *argument);

#endif
