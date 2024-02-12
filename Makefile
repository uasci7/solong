CFLAGS = -Wall -Wextra -Werror -I./minilibx -g
LFLAGS = -framework AppKit -framework OpenGL -L./minilibx -lmlx
MLX = ./minilibx/libmlx.a
LIBFT = -I./libft
PRINTF = -I./printf
GNL = $(wildcard gnl/*c)
GNLOBJS = $(GNL:.c=.o)
SRCS = main.c	walk.c	maps.c	maps_control.c	maps_control_two.c maps_control_three.c
OBJS = $(SRCS:.c=.o)
NAME = so_long

all : $(MLX) $(NAME)

$(MLX) :
	make bonus -sC LIBFT
	make -sC PRINTF
	make -sC ./minilibx

$(NAME) : $(OBJS) $(GNLOBJS)
	gcc $(OBJS) $(GNLOBJS) $(LFLAGS) ./libft/libft.a ./printf/libftprintf.a -o $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(NAME)

fclean:
	rm -rf $(OBJS) $(NAME)
	rm -rf ./gnl/*.o
	make clean -C ./minilibx
	make fclean -C ./libft
	make fclean -C ./printf
	make fclean -C ./printf/libft

norm:
	norminette ./*.c

re : fclean all

.PHONY: clean fclean re
