/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_msg.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 22:35:37 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/10 00:55:48 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERR_MSG_H
# define ERR_MSG_H

# include "libft.h"
# include <unistd.h>

# define UNKNWON_ERROR 0
# define UNEXPECTED_TOKEN 1
# define AMBIGUOUS_REDIRECT 2

void	ft_perror(int errtype, ...);
void	print_unexpected_token_err(char *next_token);
void	print_ambiguous_redirect_err(char *env_var);
void	print_unknown_err(void);

#endif
