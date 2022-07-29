/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 05:11:23 by awallet           #+#    #+#             */
/*   Updated: 2022/07/29 22:16:51 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_error(int c_type)
{
	if (c_type == C_BAD_MAP_EXT)
		ft_printf("Error\nBad file extension or not exist !\n");
	else if (c_type == C_BAD_MAP || c_type == C_BAD_MAP_SIZE)
		ft_printf("Error\nBad map or height/width\n");
	else if (c_type == C_BAD_MAP_DATA)
		ft_printf("Error\nBad map data (1,0,C,P,E,K ONLY ALLOWED)\n");
	else if (c_type == C_BAD_MAP_COUNT_P)
		ft_printf("Error\nNeed 1 player and not more.\n");
	else if (c_type == C_BAD_MAP_COUNT_E)
		ft_printf("Error\nNeed 1 exit and not more.\n");
	else if (c_type == C_BAD_MAP_COUNT_C)
		ft_printf("Error\nNeed at least 1 collectable.\n");
	else if (c_type == C_BAD_MAP_COUNT_K)
		ft_printf("Error\nNeed at least 1 enemy.\n");
	else if (c_type == C_BAD_MAP_WALL)
		ft_printf("Error\nThe map isn't closed by wall !\n");
}

void	ft_map_free(t_game *game)
{
	size_t	i;

	i = -1;
	while (game->map->maps[++i])
		free(game->map->maps[i]);
	free(game->map->maps);
}

void	ft_close(t_game *game, int c_type)
{
	ft_error(c_type);
	if (c_type != C_BAD_MAP_EXT)
	{
		if (game->map->maps)
			ft_map_free(game);
		free(game->map);
	}
	free(game->player);
	free(game->enemy);
	free(game);
	exit(E_SUCC);
}

int	ft_close_key(int key, t_game *game)
{
	if (key == ESC || key == CTRL)
	{
		mlx_loop_end(game->mlx);
		ft_destroy_data(game);
		ft_destroy_player(game);
		ft_destroy_enemy(game);
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		ft_close(game, C_KEY);
	}
	return (E_SUCC);
}

void	ft_check_wall(t_game *game)
{
	size_t	x;
	size_t	y;
	size_t	len;

	x = 0;
	y = 0;
	len = game->map->width - 1;
	while (game->map->maps[y][x])
	{
		if (game->map->maps[y][x++] != '1')
			ft_close(game, C_BAD_MAP_WALL);
	}
	y++;
	while (game->map->maps[y])
	{
		if (game->map->maps[y][0] != '1' || game->map->maps[y][len] != '1')
			ft_close(game, C_BAD_MAP_WALL);
		y++;
	}
	x = 0;
	while (game->map->maps[y - 1][x])
	{
		if (game->map->maps[y - 1][x++] != '1')
			ft_close(game, C_BAD_MAP_WALL);
	}
}
