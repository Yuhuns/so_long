NAME = so_long

NAME_BONUS = so_long_bonus

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

SRC_BONUS =	./srcs_bonus/main_bonus.c \
	./srcs_bonus/utils_bonus.c \
	./srcs_bonus/init_bonus.c \
	./srcs_bonus/close_bonus.c \
	./srcs_bonus/map_bonus.c \
	./srcs_bonus/sprite_bonus.c \
	./srcs_bonus/player_bonus.c \
	./srcs_bonus/minilibx_bonus.c \
	./srcs_bonus/destroy_bonus.c \
	./srcs_bonus/key_bonus.c \
	./srcs_bonus/image_bonus.c \
	./srcs_bonus/movement_bonus.c \
	./srcs_bonus/enemy_bonus.c \

OBJ = $(SRC:.c=.o)

DEPS = $(OBJ:.o=.d)

DEPS_BONUS = $(OBJ_BONUS:.o=.d)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

CC = gcc

all: $(NAME)

bonus : $(NAME_BONUS)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Ilibft -Imlx_linux -MMD -c $< -o $@

$(NAME): $(OBJ) 
	$(MAKE) -C libft
	$(MAKE) -C mlx_linux
	$(CC) $(OBJ)  -Llibft -lft -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lX11 -lXext -lm -lz -o $(NAME)

$(NAME_BONUS): $(OBJ_BONUS) 
	$(MAKE) -C libft
	$(MAKE) -C mlx_linux
	$(CC) $(OBJ_BONUS) -Llibft -lft -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lX11 -lXext -lm -lz -o $(NAME_BONUS)

clean:
	rm -f $(OBJ)
	rm -f $(OBJ_BONUS)
	rm -f $(DEPS_BONUS)
	rm -f $(DEPS)
	$(MAKE) -C libft clean
	$(MAKE) -C mlx_linux clean

norm:
	norminette ./srcs/ ./includes ./libft ./srcs_bonus

fclean: clean
	rm -f $(NAME) $(NAME_BONUS) libft/libft.a mlx_linux/libmlx.a

re: fclean all

.PHONY: all clean bonus norm fclean re

-include $(DEPS)
-include $(DEPS_BONUS)
