/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 13:44:23 by awallet           #+#    #+#             */
/*   Updated: 2022/07/30 13:35:09 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <fcntl.h>
# include "../mlx_linux/mlx.h"

typedef enum e_key
{
	W = 119,
	A = 97,
	D = 100,
	S = 115,
	UP = 65362,
	DOWN = 65364,
	LEFT = 65361,
	RIGHT = 65363,
	ESC = 65307,
	CTRL = 65507
}	t_key;

typedef enum e_bool
{
	TRUE = 1,
	FALSE = 0
}	t_bool;

typedef enum e_reason
{
	T_COUNT = 100,
	T_MAP = 101,
	T_SIZE_LINE = 102,
	T_SIZE_MAP = 103,
	C_DESTROY = 11,
	C_KEY = 10,
	C_BAD_MAP_WALL = 9,
	C_BAD_MAP_SIZE = 8,
	C_BAD_MAP = 7,
	C_BAD_MAP_EXT = 6,
	C_BAD_MAP_DATA = 5,
	C_BAD_MAP_COUNT_P = 4,
	C_BAD_MAP_COUNT_E = 3,
	C_BAD_MAP_COUNT_C = 2,
	E_FAIL = 1,
	E_SUCC = 0
}	t_reason;

typedef struct s_map
{
	char	**maps;
	int		width;
	int		heigth;
	int		nb_c;
	int		nb_p;
	int		nb_e;
	void	*wall;
	void	*collectable;
	void	*exit;
}	t_map;

typedef struct s_player
{
	void	*sprite[11];
	int		anim_count;
	int		x;
	int		y;
	int		nbr_count;
	int		get_cheese;
	int		anti_afk;
	int		move;
	int		can_exit;
}	t_player;

typedef struct s_game
{
	t_player	*player;
	void		*mlx;
	void		*win;
	int			img_size;
	t_map		*map;
}	t_game;

//UTILS
# define VERSION "SO_LONG: MICE 0.6a (Linux)"
# define EXT ".ber"
# define MAX_WIDTH 1650
# define MAX_HEIGTH 768
# define MIN_WIDTH 336
# define MIN_HEIGTH 144
# define MULT 48

//UTILS
char	*ft_strjoin_sl(char *s1, char *s2, char charset);
int		ft_strlen_sl(char *line);
//FREE
void	ft_close(t_game *game, int ctype);
void	ft_destroy_data(t_game *game);
void	ft_destroy_player(t_game *game);
//MAP
void	ft_map_free(t_game *game);
void	ft_init_map(char *map_file, t_game *game);
void	ft_init_game(char *map);
void	ft_check_wall(t_game *game);
//LOOP
int		ft_close_key(int key, t_game *game);
int		ft_destroy(t_game *game);
int		ft_key(int key, t_game *game);
//SPRITE
int		ft_update(t_game *game);
//PLAYER
void	ft_init_player(t_game *game);
void	ft_player_data(t_game *game, int x, int y, int id);
void	ft_check_c(t_game *game);
void	ft_anti_afk(t_game *game);
int		ft_check_e(t_game *game, int y, int x);
//MINILIBX
void	ft_init_mlx(t_game *game);
//IMAGE
void	ft_init_image(t_game *game);
//MOVE
void	ft_move_w(t_game *game);
void	ft_move_s(t_game *game);
void	ft_move_a(t_game *game);
void	ft_move_d(t_game *game);

#endif
