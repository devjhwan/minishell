# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmarinel <jmarinel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/03 14:32:42 by junghwle          #+#    #+#              #
#    Updated: 2023/12/19 01:16:29 by junghwle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

SRCDIR=.
OBJDIR=objs
SRCS=ft_strncmp.c ft_strlen.c ft_strlcpy.c ft_strdup.c ft_substr.c \
	 ft_isspace.c ft_strlcat.c ft_strjoin.c ft_strchr.c ft_isalnum.c \
	 ft_isalpha.c ft_isdigit.c ft_split.c  ft_strnstr.c ft_itoa.c ft_calloc.c \
	 ft_putstr_fd.c get_next_line.c get_next_line_utils.c \
	 list_init.c list_clear.c list_append.c list_pop.c ft_memcpy.c \
	 ft_arraylen.c ft_strcmp_case.c ft_tolower.c ft_strrchr.c ft_strcmp.c \
	 ft_putchar_fd.c ft_atoi.c ft_atoll.c ft_isnum.c ft_islonglong.c \
	 ft_toupper.c
OBJS=$(patsubst %.c, $(OBJDIR)/%.o, $(SRCS))
DEPS=$(OBJS:.o=.d)

INCLUDE=-I.
CC=cc
CFLAGS=-Wall -Werror -Wextra
DEPFLAGS=-MMD

all: $(OBJDIR) $(NAME)

$(NAME): $(OBJS) Makefile
	make -C ft_printf
	mv ft_printf/ft_printf.a $@
	ar -rcs $@ $(OBJS) 
	echo "(MINISHELL) COMPILING $@"

$(OBJDIR)/%.o: $(SRCDIR)/%.c Makefile 
	$(CC) $(DEPFLAGS) $(CFLAGS) $(INCLUDE) -c -o $@ $<
	echo "(MINISHELL) COMPILING $@"

$(OBJDIR): Makefile
	mkdir -p $@

clean:
	make -C ft_printf fclean
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
.SILENT:
