/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 22:08:41 by awallet           #+#    #+#             */
/*   Updated: 2022/07/27 01:55:41 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->map->width * MULT,
			game->map->heigth * MULT, VERSION);
	ft_init_image(game);
	mlx_key_hook(game->win, ft_key, game);
	mlx_hook(game->win, 2, (1L << 0), ft_close_key, game);
	mlx_hook(game->win, 17, (1L << 24), ft_destroy, game);
	mlx_loop_hook(game->mlx, ft_update, game);
	mlx_loop(game->mlx);
}
