NAME = fractol

FILES = main.c

PRINTF = ft_printf

APRINTF = ft_printf/libftprintf.a

BFILES = fractol_bonus/main_bonus.c

ASSETS = assets/init.c

BASSETS = fractol_bonus/assets/colors_bonus.c

MOUVEMENTS = movements/close.c movements/zoom.c

BMOUVEMENTS = fractol_bonus/movements/movement_bonus.c fractol_bonus/movements/zoom_bonus.c

SETS = sets/julia.c sets/mandelbrot.c

BSETS = fractol_bonus/sets/julia.c fractol_bonus/sets/mandelbrot.c fractol_bonus/sets/burning_ship_bonus.c

LIBFT = libft/ft_libft.c

HEADER = fractol.h ft_printf/ft_printf.h

BHEADER = fractol_bonus/fractol_bonus.h ft_printf/ft_printf.h

FLAGS = -Wall -Werror -Wextra

MLX = -lmlx -framework OpenGL -framework appKit

OBJS = $(FILES:.c=.o) $(ASSETS:.c=.o) $(MOUVEMENTS:.c=.o) $(SETS:.c=.o) $(LIBFT:.c=.o)

BOBJS = $(BFILES:.c=.o) $(BASSETS:.c=.o) $(ASSETS:.c=.o) $(BMOUVEMENTS:.c=.o) $(BSETS:.c=.o) $(LIBFT:.c=.o)

%.o: %.c
	cc $(FLAGS)  -c $< -o $@

$(NAME)	: $(OBJS) $(APRINTF) $(HEADER)
	cc $(FLAGS) $(MLX) $(APRINTF) $(FILES) $(ASSETS) $(MOUVEMENTS) $(LIBFT) $(SETS) -o $(NAME)

$(APRINTF) : 
	$(MAKE) -C $(PRINTF)

all : $(NAME)

bonus : $(BOBJS) $(BHEADER) $(APRINTF)
	cc $(FLAGS) $(MLX) $(APRINTF) $(BFILES) $(ASSETS) $(BASSETS) $(BMOUVEMENTS) $(LIBFT) $(BSETS) -o $(NAME)

re : fclean all

clean : 
	rm -rf $(OBJS) $(BOBJS)
	$(MAKE) -C $(PRINTF) clean

fclean : clean
	rm -rf $(NAME)
	$(MAKE) -C $(PRINTF) fclean

.PHONY:all clean fclean re bonus
