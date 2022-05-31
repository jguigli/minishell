NAME = gnl.a

SRC = get_next_line.c \
		get_next_line_utils.c \

OBJ = $(SRC:.c=.o)

CC = gcc

FLAG = -Wall -Werror -Wextra 

HEADER = ./get_next_line.h

all : $(NAME)

%.o : %.c
	$(CC) -c $< -o $@

$(NAME) : $(OBJ) $(HEADER)
	ar -rcs $(NAME) $(OBJ)
	ranlib $(NAME)

clean :
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re