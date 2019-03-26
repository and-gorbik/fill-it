NAME = fillit
SRC = item.c container.c map.c main.c
OBJ = $(SRC : .c = .o)
LIB = libft.a
all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -o $(NAME) $(SRC) $(LIB)
clean:
	rm -rf $(NAME)
fclean: clean
	rm -rf $(OBJ)
re: fclean all
