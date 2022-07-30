/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:16:41 by awallet           #+#    #+#             */
/*   Updated: 2022/07/30 15:11:08 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_exit_error(t_game *game)
{
	ft_printf("Info\nYou need %d cheese(s) more to exit !\n",
		(game->map->nb_c - game->player->get_cheese));
}

void	ft_move_w(t_game *game)
{
	int	x;
	int	y;

	y = game->player->y;
	x = game->player->x;
	if (game->map->maps[y - 1][x] != '1')
	{
		if (!ft_check_e(game, y - 1, x))
		{
			game->player->y -= 1;
			if (game->map->maps[y][x] != 'P')
				game->map->maps[y][x] = '1';
			ft_check_c(game);
			game->player->move = TRUE;
			game->player->nbr_count += 1;
		}
		else
			ft_exit_error(game);
	}
}

void	ft_move_s(t_game *game)
{
	int	x;
	int	y;

	y = game->player->y;
	x = game->player->x;
	if (game->map->maps[y + 1][x] != '1')
	{
		if (!ft_check_e(game, y + 1, x))
		{
			game->player->y += 1;
			if (game->map->maps[y][x] != 'P')
				game->map->maps[y][x] = '1';
			ft_check_c(game);
			game->player->move = TRUE;
			game->player->nbr_count += 1;
		}
		else
			ft_exit_error(game);
	}
}

void	ft_move_a(t_game *game)
{
	int	x;
	int	y;

	y = game->player->y;
	x = game->player->x;
	if (game->map->maps[y][x - 1] != '1')
	{
		if (!ft_check_e(game, y, x - 1))
		{
			game->player->x -= 1;
			if (game->map->maps[y][x] != 'P')
				game->map->maps[y][x] = '1';
			ft_check_c(game);
			game->player->move = TRUE;
			game->player->nbr_count += 1;
		}
		else
			ft_exit_error(game);
	}
}

void	ft_move_d(t_game *game)
{
	int	x;
	int	y;

	y = game->player->y;
	x = game->player->x;
	if (game->map->maps[y][x + 1] != '1')
	{
		if (!ft_check_e(game, y, x + 1))
		{
			game->player->x += 1;
			if (game->map->maps[y][x] != 'P')
				game->map->maps[y][x] = '1';
			ft_check_c(game);
			game->player->move = TRUE;
			game->player->nbr_count += 1;
		}
		else
			ft_exit_error(game);
	}
}
