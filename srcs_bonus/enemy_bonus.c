/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 18:51:11 by awallet           #+#    #+#             */
/*   Updated: 2022/07/29 22:39:49 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_enemy_data(t_game *game, int x, int y, int id)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->enemy->sprite[id],
		x * MULT, y * MULT);
}

void	ft_check_k_count(t_game *game)
{
	if (game->map->nb_k <= 0)
		ft_close(game, C_BAD_MAP_COUNT_K);
}

int	ft_check_k(t_game *game, int y, int x)
{
	char	*dead;

	dead = "GAME OVER\nYou get killed by a fly cheese vampire !\n";
	if (game->map->maps[y][x] == 'K')
	{
		ft_printf("%sYou miss %d cheese(s) and lost %d cheese(s) !\n",
			dead,
			game->map->nb_c - game->player->get_cheese,
			game->player->get_cheese);
		ft_destroy(game);
		return (TRUE);
	}
	return (FALSE);
}

void	ft_put_enemy_image(t_game *game, char *path, int id, char type)
{
	if (type == 'K')
		game->enemy->sprite[id] = mlx_xpm_file_to_image(game->mlx,
				path,
				&game->img_size,
				&game->img_size);
}

void	ft_init_enemy(t_game *game)
{
	game->enemy = (t_enemy *)malloc(sizeof(t_enemy));
	if (!game->enemy)
		return ;
}
