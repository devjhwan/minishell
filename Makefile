# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/03 14:32:42 by junghwle          #+#    #+#              #
#    Updated: 2023/11/07 19:50:00 by junghwle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=minishell

SRCDIR=./src
PARSE_DIR=parse
OBJDIR=objs
MAIN_SRC=main.c
PARSE_SRC=parse_input.c token.c command.c lexer.c parser.c executor.c \
		  expander.c print_lexer.c ismetacharacter.c
SRCS=$(MAIN_SRC) $(PARSE_SRC)
OBJS=$(patsubst %.c, $(OBJDIR)/%.o, $(SRCS))
DEPS=$(OBJS:.o=.d)

INCLUDE=-I./inc -I./libft
CC=cc
CFLAGS=-Wall -Werror -Wextra
DEPFLAGS=-MMD
LIBFT=libft/libft.a
LDFLAGS=-L${HOME}/homebrew/opt/readline/lib
CPPFLAGS=-I${HOME}/homebrew/opt/readline/include

all: $(OBJDIR) libft $(NAME)

$(NAME): $(OBJS) $(LIBFT) Makefile
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBFT) -lreadline $(LDFLAGS)
	echo "(MINISHELL)COMPILING $@"

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(LIBFT) Makefile
	$(CC) $(DEPFLAGS) $(CFLAGS) $(INCLUDE) -c -o $@ $< $(CPPFLAGS)
	echo "(MINISHELL)COMPILING $@"

$(OBJDIR)/%.o: $(SRCDIR)/$(PARSE_DIR)/%.c $(LIBFT) Makefile
	$(CC) $(DEPFLAGS) $(CFLAGS) $(INCLUDE) -c -o $@ $< $(CPPFLAGS)
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
#cambio en el main
.SILENT:
