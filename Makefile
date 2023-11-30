# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/03 14:32:42 by junghwle          #+#    #+#              #
#    Updated: 2023/11/30 15:21:05 by junghwle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=minishell

SRCDIR=./src
PARSE_DIR=parse
JOIN_TOKENS_DIR=$(PARSE_DIR)/join_tokens
PARSE_HELPER_DIR=$(PARSE_DIR)/parse_helper
EXPAND_DIR=$(PARSE_DIR)/expand
TOKEN_CHECKER_DIR=$(PARSE_DIR)/token_checker
EXECUTER_DIR=executer
ERR_MSG_DIR=err_msg
BUILTINS_DIR=builtins
OBJDIR=objs
MAIN_SRC=main.c terminal_setting.c signal_handler.c minishell.c \
		 clear_command_list.c
PARSE_SRC=parse_input.c token.c lexer.c parser.c expander.c \
		  command_builder.c
JOIN_TOKENS_SRC=join_content.c join_arguments.c join_env_var_arguments.c \
				join_redirections.c
PARSE_HELPER_SRC=print_token_list.c ismetacharacter.c append_substr.c \
				 replace_substr.c isquote.c
EXPAND_SRC=expand_env_variables.c remove_quotes.c search_env_value.c \
		   merge_consecutive_arguments.c remove_blanks.c
TOKEN_CHECKER_SRC=check_token_error.c check_redirection.c check_pipe.c
EXECUTER_SRC=executer.c utils_exec.c utils2_exec.c redirect.c \
		  	 pathfinder.c commander.c files.c
ERR_MSG_SRC=ft_perror.c print_unknown_err.c print_unexpected_token_err.c \
			print_ambiguous_redirect_err.c print_export_invalid_identifier.c
BUILTINS_SRC=env.c export.c export2.c cd.c pwd.c
SRCS=$(MAIN_SRC) $(PARSE_SRC) $(JOIN_TOKENS_SRC) $(PARSE_HELPER_SRC) \
	 $(EXPAND_SRC) $(TOKEN_CHECKER_SRC) $(COMMAND_BUILDER_SRC) \
	 $(EXECUTER_SRC) $(ERR_MSG_SRC) $(BUILTINS_SRC)
OBJS=$(patsubst %.c, $(OBJDIR)/%.o, $(SRCS))
DEPS=$(OBJS:.o=.d)

INCLUDE=-I./inc -I./libft
CC=cc
DEBUG=-fsanitize="address,undefined" -g
CFLAGS=-Wall -Werror -Wextra
DEPFLAGS=-MMD
LIBFT=libft/libft.a
#LDFLAGS=-L/opt/homebrew/lib
#CPPFLAGS=-I/opt/homebrew/include
LDFLAGS=-L${HOME}/homebrew/opt/readline/lib
CPPFLAGS=-I${HOME}/homebrew/opt/readline/include

all: $(OBJDIR) libft $(NAME)

$(NAME): $(OBJS) $(LIBFT) Makefile
	$(CC) $(DEBUG) $(CFLAGS) -o $@ $(OBJS) $(LIBFT) -lreadline $(LDFLAGS)
	echo "(MINISHELL) COMPILING $@"

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(LIBFT) Makefile
	$(CC) $(DEBUG) $(DEPFLAGS) $(CFLAGS) $(INCLUDE) -c -o $@ $< $(CPPFLAGS)
	echo "(MINISHELL) COMPILING $@"

$(OBJDIR)/%.o: $(SRCDIR)/$(PARSE_DIR)/%.c $(LIBFT) Makefile
	$(CC) $(DEBUG) $(DEPFLAGS) $(CFLAGS) $(INCLUDE) -c -o $@ $< $(CPPFLAGS)
	echo "(MINISHELL) COMPILING $@"

$(OBJDIR)/%.o: $(SRCDIR)/$(JOIN_TOKENS_DIR)/%.c $(LIBFT) Makefile
	$(CC) $(DEBUG) $(DEPFLAGS) $(CFLAGS) $(INCLUDE) -c -o $@ $< $(CPPFLAGS)
	echo "(MINISHELL) COMPILING $@"

$(OBJDIR)/%.o: $(SRCDIR)/$(PARSE_HELPER_DIR)/%.c $(LIBFT) Makefile
	$(CC) $(DEBUG) $(DEPFLAGS) $(CFLAGS) $(INCLUDE) -c -o $@ $< $(CPPFLAGS)
	echo "(MINISHELL) COMPILING $@"

$(OBJDIR)/%.o: $(SRCDIR)/$(EXPAND_DIR)/%.c $(LIBFT) Makefile
	$(CC) $(DEBUG) $(DEPFLAGS) $(CFLAGS) $(INCLUDE) -c -o $@ $< $(CPPFLAGS)
	echo "(MINISHELL) COMPILING $@"

$(OBJDIR)/%.o: $(SRCDIR)/$(TOKEN_CHECKER_DIR)/%.c $(LIBFT) Makefile
	$(CC) $(DEBUG) $(DEPFLAGS) $(CFLAGS) $(INCLUDE) -c -o $@ $< $(CPPFLAGS)
	echo "(MINISHELL) COMPILING $@"

$(OBJDIR)/%.o: $(SRCDIR)/$(EXECUTER_DIR)/%.c Makefile
	$(CC) $(DEBUG) $(DEPFLAGS) $(CFLAGS) $(INCLUDE) -c -o $@ $< $(CPPFLAGS)
	echo "(MINISHELL) COMPILING $@"

$(OBJDIR)/%.o: $(SRCDIR)/$(ERR_MSG_DIR)/%.c $(LIBFT) Makefile
	$(CC) $(DEBUG) $(DEPFLAGS) $(CFLAGS) $(INCLUDE) -c -o $@ $< $(CPPFLAGS)
	echo "(MINISHELL) COMPILING $@"

$(OBJDIR)/%.o: $(SRCDIR)/$(BUILTINS_DIR)/%.c $(LIBFT) Makefile
	$(CC) $(DEBUG) $(DEPFLAGS) $(CFLAGS) $(INCLUDE) -c -o $@ $< $(CPPFLAGS)
	echo "(MINISHELL) COMPILING $@"

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
