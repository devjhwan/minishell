# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/03 14:32:42 by junghwle          #+#    #+#              #
#    Updated: 2023/11/30 16:17:44 by junghwle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=ft_printf.a

SRCDIR=./srcs
OBJDIR=objs
SRCS=ft_digit.c ft_hex_fd.c ft_hexnum.c ft_parse.c ft_printf.c ft_printf_fd.c \
	 ft_printfnbr_fd.c ft_ptr.c ft_ui.c utils.c
OBJS=$(patsubst %.c, $(OBJDIR)/%.o, $(SRCS))
DEPS=$(OBJS:.o=.d)

INCLUDE=-I. -I/includes -I..
CC=cc
CFLAGS=-Wall -Werror -Wextra
DEPFLAGS=-MMD

all: $(OBJDIR) $(NAME)

$(NAME): $(OBJS) Makefile
	ar -rcs $@ $(OBJS) 
	echo "(MINISHELL) COMPILING $@"

$(OBJDIR)/%.o: $(SRCDIR)/%.c Makefile 
	$(CC) $(DEPFLAGS) $(CFLAGS) $(INCLUDE) -c -o $@ $<
	echo "(MINISHELL) COMPILING $@"

$(OBJDIR): Makefile
	mkdir -p $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
.SILENT:
