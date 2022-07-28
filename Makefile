NAME = minishell

SRC = minishell.c \
		./src/tokenisation/get_tokens_1.c \
		./src/tokenisation/get_tokens_2.c \
		./src/tokenisation/get_tokens_2bis.c \
		./src/tokenisation/get_tokens_3.c \
		./src/tokenisation/parse_tokens_1.c \
		./src/tokenisation/parse_tokens_2.c \
		./src/tokenisation/tag_tokens_1.c \
		./src/tokenisation/tag_tokens_2.c \
		./src/tokenisation/tag_tokens_3.c \
		./src/tokenisation/tag_tokens_4.c \
		./src/tokenisation/tag_tokens_5.c \
		./src/tokenisation/utils_tokens_1.c \
		./src/tokenisation/utils_tokens_2.c \
		./src/tokenisation/utils_tokens_3.c \
		./src/sig/signal.c \
		./src/sig/signal_2.c \
		./src/inits/init_struct_1.c \
		./src/inits/init_struct_2.c \
		./src/parse_args/parsing_args_1.c \
		./src/parse_args/parsing_args_2.c \
		./src/parse_args/parsing_args_3.c \
		./src/parse_args/parsing_args_4.c \
		./src/parse_args/parsing_args_5.c \
		./src/parse_args/parsing_args_6.c \
		./src/parse_args/parsing_args_7.c \
		./src/parse_args/parsing_args_8.c \
		./src/parse_args/parsing_args_8bis.c \
		./src/parse_args/parsing_args_9.c \
		./src/parse_args/parsing_args_10.c \
		./src/parse_args/parsing_args_11.c \
		./src/parse_args/parsing_args_12.c \
		./src/parse_args/parsing_args_utils_1.c \
		./src/parse_args/parsing_args_utils_2.c \
		./src/parse_args/parsing_args_residus.c \
		./src/parse_args/parsing_args_residus_bis.c\
		./src/redir/manage_heredoc_1.c \
		./src/redir/manage_heredoc_2.c \
		./src/redir/manage_heredoc_3.c \
		./src/redir/redir_expansion_utils.c \
		./src/exec_prog/exec_manage_redir_1.c \
		./src/exec_prog/exec_manage_redir_2.c \
		./src/exec_prog/exec_manage_redir_3.c \
		./src/env/get_copy.c \
		./src/env/get_var_env.c \
		./src/env/get_env_i.c \
		./src/builtin/export/export.c \
		./src/builtin/export/export2.c \
		./src/builtin/export/export3.c \
		./src/builtin/export/export4.c \
		./src/builtin/export/export5.c \
		./src/prompt/get_prompt.c \
		./src/err_msgs/err_messages.c \
		./src/err_msgs/err_messages2.c \
		./src/exec_prog/exec_prog.c \
		./src/exec_prog/exec_prog_complex.c \
		./src/exec_prog/exec_prog_simple.c \
		./src/exec_prog/child_process_simple.c \
		./src/exec_prog/child_process_complex.c \
		./src/parse_args/expansion.c \
		./src/parse_args/expansion2.c \
		./src/parse_args/expansion3.c \
		./src/parse_args/delete_node_expansion.c \
		./src/parse_args/quote_removal.c \
		./src/parse_args/word_splitting.c \
		./src/exec_prog/exec_prog_utils.c \
		./src/exec_prog/exec_prog_utils2.c \
		./src/builtin/cd/cd.c \
		./src/builtin/cd/cd2.c \
		./src/builtin/echo.c \
		./src/builtin/env.c \
		./src/builtin/exit.c \
		./src/builtin/pwd.c \
		./src/builtin/unset/unset.c \
		./src/builtin/unset/unset2.c \
		./src/freeing/free_and_error.c \
		./src/freeing/free_main.c \
		./src/freeing/free_exec.c \
		./src/freeing/closing.c \
		./src/check/check_quote.c \

OBJ = $(SRC:.c=.o)

CC = cc

FLAG = -Wall -Werror -Wextra

HEADER = ./includes/minishell.h
INC = 	-I./includes/	\
		-I./libft/includes \

LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

GNL_PATH		=	./gnl
GNL				= 	$(GNL_PATH)/gnl.a

all : $(NAME)

%.o : %.c
	$(CC) $(FLAG) -c $< -o $@ 

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

re: fclean all

.PHONY : all clean fclean re
