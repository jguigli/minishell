NAME = minishell

SRC = minishell.c \
		./src/prompt/get_prompt.c \
		./src/env/get_copy.c \
		./src/parse_args/parsing_args.c \
		./src/parse_args/expansion.c \
		./src/parse_args/expansion2.c \
		./src/parse_args/expansion3.c \
		./src/inits/init_struct.c \
		./src/exit_free/exit_free.c \
		./src/check/check_quote.c \
		./src/tokenisation/get_tokens.c \
		./src/ast/building_ast.c \
		./src/sig/signal.c \
		./src/err_msgs/err_messages.c \
		./src/redir/manage_heredoc.c \
		./src/exec_prog/exec_prog.c \
		./src/exec_prog/exec_manage_redir.c \
		./src/exec_prog/exec_prog_utils.c \
		./src/exec_prog/exec_prog_utils2.c \
		./src/exec_prog/exec_prog_simple.c \
		./src/exec_prog/exec_prog_complex.c \
		./src/env/get_var_env.c \
		./src/env/get_env_i.c \
		./src/builtin/cd.c \
		./src/builtin/echo.c \
		./src/builtin/env.c \
		./src/builtin/exit.c \
		./src/builtin/export/export.c \
		./src/builtin/export/export2.c \
		./src/builtin/pwd.c \
		./src/builtin/unset.c \
		./src/freeing/freeing.c \
		# ./src/process_launch/p_launch.c \

OBJ = $(SRC:.c=.o)

CC = cc

FLAG = -Wall -Werror -Wextra -g3 -fsanitize=address 

HEADER = ./includes/minishell.h
INC = 	-I./includes/	\
		-I./libft/includes

LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

GNL_PATH		=	./gnl
GNL				=	$(GNL_PATH)/gnl.a

all : $(NAME)

%.o : %.c
	$(CC) -c $< -o $@ 

$(NAME) : $(OBJ) $(LIBFT) $(GNL) $(HEADER)
	$(CC) $(FLAG) $(OBJ) $(LIBFT) $(GNL) $(INC) -lreadline -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

$(GNL):
	$(MAKE) -C $(GNL_PATH)

clean :
	$(MAKE) -C $(LIBFT_PATH) clean
	$(MAKE) -C $(GNL_PATH) clean
	rm -rf $(OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(MAKE) -C $(GNL_PATH) fclean
	rm -f $(NAME)

# clean :
# 	$(MAKE) -C $(GNL_PATH) clean
# 	rm -rf $(OBJ)

# fclean: clean
# 	$(MAKE) -C $(GNL_PATH) fclean
# 	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
