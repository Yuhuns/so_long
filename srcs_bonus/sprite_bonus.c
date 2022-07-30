/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 21:50:02 by awallet           #+#    #+#             */
/*   Updated: 2022/07/30 22:54:50 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	ft_put_data(t_game *game, int id)
{
	int	x;
	int	y;

	if (id % 2)
		mlx_clear_window(game->mlx, game->win);
	y = 0;
	while (game->map.maps[y])
	{
		x = 0;
		while (game->map.maps[y][x])
		{
			if (game->map.maps[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->map.wall,
					x * MULT, y * MULT);
			else if (game->map.maps[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win,
					game->map.collectable, x * MULT, y * MULT);
			else if (game->map.maps[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win,
					game->map.exit, x * MULT, y * MULT);
			ft_put_data_bis(game, y, x, id);
			x++;
		}
		y++;
	}
}

static void	ft_sprite(t_game *game)
{
	static int	anim_id = 0;

	ft_put_data(game, anim_id);
	anim_id++;
	if (anim_id == 10)
		anim_id = 0;
}

static void	ft_counter(t_game *game)
{
	char	*move_count;
	char	*cheese_count;
	char	*player_cheese;
	int		color;

	if (game->player.get_cheese == game->map.nb_c)
		color = 0x0008CC0A;
	else
		color = 0x00FF0000;
	move_count = ft_itoa(game->player.nbr_count);
	cheese_count = ft_itoa(game->map.nb_c);
	player_cheese = ft_itoa(game->player.get_cheese);
	mlx_string_put(game->mlx, game->win, 5, 20, 0x00FFFF00,
		"Moves:");
	mlx_string_put(game->mlx, game->win, 5, 35, 0x00FFFFFF, move_count);
	mlx_string_put(game->mlx, game->win, 52, 21, 0x00FFFF00,
		"Cheese:");
	mlx_string_put(game->mlx, game->win, 52, 35, color, player_cheese);
	mlx_string_put(game->mlx, game->win, 67, 35, 0x00FFFFFF,
		"/");
	mlx_string_put(game->mlx, game->win, 77, 35, color, cheese_count);
	free(move_count);
	free(cheese_count);
	free(player_cheese);
}

int	ft_update(t_game *game)
{
	usleep(game->player.anim_count);
	ft_sprite(game);
	ft_counter(game);
	ft_anti_afk(game);
	return (E_SUCC);
}
