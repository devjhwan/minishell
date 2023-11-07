# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/03 14:32:42 by junghwle          #+#    #+#              #
#    Updated: 2023/11/07 15:36:46 by junghwle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

SRCDIR=.
OBJDIR=objs
SRCS=ft_strncmp.c ft_strlen.c ft_strlcpy.c ft_strdup.c ft_substr.c ft_isspace.c\
	 list_init.c list_clear.c list_append.c list_pop.c \
	 tree_init.c tree_clear.c tree_new_node.c tree_append_left.c \
	 tree_append_right.c
OBJS=$(patsubst %.c, $(OBJDIR)/%.o, $(SRCS))
DEPS=$(OBJS:.o=.d)

INCLUDE=-I.
CC=cc
CFLAGS=-Wall -Werror -Wextra
DEPFLAGS=-MMD

all: $(OBJDIR) $(NAME)

$(NAME): $(OBJS) Makefile
	ar -rcs $@ $(OBJS) 
	echo "(MINISHELL)COMPILING $@"

$(OBJDIR)/%.o: $(SRCDIR)/%.c Makefile 
	$(CC) $(DEPFLAGS) $(CFLAGS) $(INCLUDE) -c -o $@ $<
	echo "(MINISHELL)COMPILING $@"

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
