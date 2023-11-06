# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/03 14:32:42 by junghwle          #+#    #+#              #
#    Updated: 2023/11/06 21:19:56 by junghwle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=minishell

SRCDIR=.
OBJDIR=objs
SRCS=main.c
OBJS=$(patsubst %.c, $(OBJDIR)/%.o, $(SRCS))
DEPS=$(OBJS:.o=.d)

INCLUDE=-I. -I./libft
CC=cc
CFLAGS=-Wall -Werror -Wextra
DEPFLAGS=-MMD
LIBFT=libft/libft.a
LDFLAGS=-L/goinfre/${USER}/homebrew/opt/readline/lib
CPPFLAGS=-I/goinfre/${USER}/homebrew/opt/readline/include

all: $(OBJDIR) $(NAME)

$(NAME): libft $(OBJS) Makefile
	$(CC) $(CFLAGS) $(EXTRAFLAGS) -o $@ $(OBJS) $(LIBFT) \
	-lreadline $(LDFLAGS)
	echo "(MINISHELL)COMPILING $@"

$(OBJDIR)/%.o: $(SRCDIR)/%.c Makefile
	$(CC) $(DEPFLAGS) $(CFLAGS) $(INCLUDE) -c -o $@ $< \
		$(CPPFLAGS)
	echo "(MINISHELL)COMPILING $@"

$(OBJDIR): Makefile
	mkdir -p $@

libft:
	make -C libft

clean:
	make -C libft fclean
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re libft
.SILENT:
