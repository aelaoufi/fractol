NAME = fractol

FILES = main.c

ASSETS = assets/colors.c assets/init.c

MOUVEMENTS = movements/movement.c movements/zoom.c

SETS = sets/julia.c sets/mandelbrot.c sets/burning_ship.c

LIBFT = libft/ft_libft.c

HEADER = fractol.h

FLAGS = -Wall -Werror -Wextra

MLX = -lmlx -framework OpenGL -framework appKit

OBJS = $(FILES:.c=.o) $(ASSETS:.c=.o) $(MOUVEMENTS:.c=.o) $(SETS:.c=.o) $(LIBFT:.c=.o)

%.o: %.c
	cc $(FLAGS)  -c $< -o $@

$(NAME)	: $(OBJS) $(HEADER)
	cc $(FLAGS) $(MLX) -I $(HEADER) $(FILES) $(ASSETS) $(MOUVEMENTS) $(LIBFT) $(SETS) -o $(NAME)

all : $(NAME)

re : fclean all

clean : 
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

.PHONY:all clean fclean re bonus
