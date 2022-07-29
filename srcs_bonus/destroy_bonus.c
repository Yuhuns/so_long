/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 22:16:58 by awallet           #+#    #+#             */
/*   Updated: 2022/07/29 20:04:54 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_destroy_data(t_game *game)
{
	mlx_destroy_image(game->mlx, game->map->wall);
	mlx_destroy_image(game->mlx, game->map->exit);
	mlx_destroy_image(game->mlx, game->map->collectable);
}

void	ft_destroy_player(t_game *game)
{
	int	i;

	i = 0;
	while (i < 11)
		mlx_destroy_image(game->mlx, game->player->sprite[i++]);
}

void	ft_destroy_enemy(t_game *game)
{
	int	i;

	i = 0;
	while (i < 11)
		mlx_destroy_image(game->mlx, game->enemy->sprite[i++]);
}

int	ft_destroy(t_game *game)
{
	mlx_loop_end(game->mlx);
	ft_destroy_data(game);
	ft_destroy_player(game);
	ft_destroy_enemy(game);
	mlx_clear_window(game->mlx, game->win);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	ft_close(game, C_DESTROY);
	return (E_SUCC);
}
