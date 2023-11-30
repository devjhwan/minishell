/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:17:20 by junghwle          #+#    #+#             */
/*   Updated: 2023/11/30 16:32:46 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "ft_printf/includes/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <limits.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 19
# endif

int		ft_arraylen(char **arr);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
int		ft_isdigit(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_isspace(char ch);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
char	*get_next_line(int fd);
char	*ft_strchr_line(const char *s, int c);
size_t	ft_len_line(const char *s);
char	*ft_strjoin_line(char *s1, char *s2);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	**ft_split(char const *s, char *set);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_itoa(int nb);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		ft_strcmp_case(const char *s1, const char *s2, int flag);
int		ft_tolower(int c);
int		ft_strcmp(const char *s1, const char *s2);

#endif