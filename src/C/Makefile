NAME = fillit
SRC = item.c container.c map.c main.c del.c
# OBJ = $(SRC : .c = .o)
LDIR = libft
LNAME = libft.a

all: $(NAME)
	
$(NAME):
	@make -C $(LDIR)
	gcc -Wall -Wextra -Werror -o $(NAME) $(SRC) $(LDIR)/$(LNAME)

clean:
	@make -C $(LDIR) clean

fclean: clean
	@make -C $(LDIR) fclean
	rm -f $(NAME)

re: fclean all
	


