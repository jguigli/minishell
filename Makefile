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
		./src/env/get_var_env.c \
		# ./src/process_launch/p_launch.c \

OBJ = $(SRC:.c=.o)

CC = gcc

FLAG = -Wall -Werror -Wextra -g3 -fsanitize=address 

HEADER = ./includes/minishell.h

LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

all : $(NAME)

%.o : %.c
	$(CC) -c $< -o $@

$(NAME) : $(OBJ) $(LIBFT) $(HEADER)
	$(CC) $(FLAG) $(OBJ) $(LIBFT) -lreadline -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

clean :
	$(MAKE) -C $(LIBFT_PATH) clean
	rm -rf $(OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
