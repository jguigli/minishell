NAME = minishell

SRC = minishell.c \
		./src/prompt/get_prompt.c \
		./src/env/get_copy.c \
		./src/parse_args/parsing_args.c \
		./src/exit_free/exit_free.c \
		./src/check/check_quote.c \
		./src/tokenisation/get_tokens.c \

OBJ = $(SRC:.c=.o)

CC = gcc

FLAG = -Wall -Werror -Wextra

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
