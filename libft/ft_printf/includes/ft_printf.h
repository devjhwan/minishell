/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:41:33 by jmarinel          #+#    #+#             */
/*   Updated: 2023/11/30 16:27:27 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft.h"

/*PRINCIPALES*/
int		ft_printf(const char *s, ...);
int		ft_search(va_list args, char s);
int		ft_parse(va_list args, const char *s);

/*UTILS*/
int		ft_putchar(char c);
int		ft_putstr(char *s);

/*DIGITS*/
int		ft_print_integuer(int num);
int		nbr_len(int n);
int		ft_putnbr(int n);

/*HEXA*/
int		ft_hexnum(unsigned int nbr, char s);
int		hexa_len(unsigned int n);
int		ft_printhexa(long int nb, char *base);

/*UI*/
int		ft_ui(unsigned int nbr);
int		ft_putui(unsigned int n);
int		ui_len(unsigned int n);

/*PTR*/
int		ft_ptr(unsigned long long n);
int		ft_printptr(unsigned long long n, char *base);
int		ptr_len(unsigned long long n);

int		ft_test_write_fd(int test, int i);
int		ft_printchar_fd(int c, int fd);
int		ft_printstr_fd(char *str, int fd);
int		ft_prints_fd(va_list arg, char c, int fd);
int		ft_printf_fd(const int fd, const char *str, ...);
int		ft_printnbr_fd(int n, int fd);
int		ft_printundhex_fd(unsigned int nb, int test, int fd);
int		ft_printunnbr_fd(unsigned int num, int test, int fd);
int		ft_printpnt_fd(unsigned long pointer, int fd);
int		ft_printuphex_fd(unsigned int nb, int test, int fd);

#endif