# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/03 14:32:42 by junghwle          #+#    #+#              #
#    Updated: 2023/11/06 19:50:04 by junghwle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=minishell

SRCDIR=.
OBJDIR=objs
SRCS=main.c
OBJS=$(patsubst %.c, $(OBJDIR)/%.o, $(SRCS))
DEPS=$(OBJS:.o=.d)

INCLUDE=-I.
CC=cc
CFLAGS=-Wall -Werror -Wextra
DEPFLAGS=-MMD

all: $(OBJDIR) $(NAME)

$(NAME): $(OBJS) Makefile
	$(CC) $(CFLAGS) $(EXTRAFLAGS) -o $@ $(OBJS) \
	-lreadline $(shell echo $$LDFLAGS)
	echo "(MINISHELL)COMPILING $@"

$(OBJDIR)/%.o: $(SRCDIR)/%.c Makefile 
	$(CC) $(DEPFLAGS) $(CFLAGS) $(INCLUDE) -c -o $@ $<\
		$(shell echo $$CPPFLAGS)
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
