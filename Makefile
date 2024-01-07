NAME = fractol

CFLAGS = -Wall -Wextra -Werror 

SRC = general.c mandelbrot.c julia.c fractol.c ft_utils.c burning_ship.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	cc $(CFLAGS) $(OBJ) -o $(NAME) -lmlx -framework OpenGL -framework AppKit

clean:
	rm -f $(OBJ)

fclean: clean 
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re