NAME = fractol

SRCS = fractol.c\
	key_hooks.c\
	iterations.c\
	colour.c\
	check_args.c

OBJS = $(patsubst %.c, %.o, $(SRCS))

FLAGS = -Wall -Werror -Wextra -g

FRAMEWORK = -framework OpenGL -framework AppKit

INC_MLX = -Lminilibx -lmlx

all: $(NAME)

$(NAME) : $(OBJS)
	make -C minilibx
	make -C libft
	gcc $(FLAGS) $(INC_MLX) $(FRAMEWORK) $(OBJS) ./libft/libft.a -o $(NAME)

%.o : %.c fractol.h
	gcc $(FLAGS) -c $< -o $@

clean :
	make -C minilibx clean
	make -C libft clean
	rm -f $(OBJS)

fclean : clean
	make -C libft fclean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re