NAME = so_long

SRC =	./srcs/main.c \
	./srcs/utils.c \
	./srcs/init.c \
	./srcs/close.c \
	./srcs/map.c \
	./srcs/sprite.c \
	./srcs/player.c \
	./srcs/minilibx.c \
	./srcs/destroy.c \
	./srcs/key.c \
	./srcs/image.c \
	./srcs/movement.c \

OBJ = $(SRC:.c=.o)

CC = gcc

all: $(NAME)

%.o: %.c
	$(CC) -g3 -Wall -Wextra -Werror -I/usr/include -Ilibft -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJ) 
	make -C libft
	make -C mlx_linux
	$(CC) $(OBJ)  -Llibft -lft -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lX11 -lXext -lm -lz -o $(NAME)


clean:
	rm -f $(OBJ)
	make -C libft clean
	make -C mlx_linux clean

norm:
	norminette ./srcs/ ./includes ./libft

fclean: clean
	rm -f $(NAME) libft/libft.a mlx_linux/libmlx.a

re: fclean all

.PHONY: all clean norm fclean re
