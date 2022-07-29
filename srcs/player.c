/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 21:54:21 by awallet           #+#    #+#             */
/*   Updated: 2022/07/29 17:36:06 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_player_data(t_game *game, int x, int y, int id)
{
	if (!game->player->x && !game->player->y)
	{
		game->player->x = x;
		game->player->y = y;
	}
	mlx_put_image_to_window(game->mlx, game->win,
		game->player->sprite[id],
		game->player->x * MULT, game->player->y * MULT);
}

void	ft_check_c(t_game *game)
{
	if (game->map->maps[game->player->y][game->player->x] == 'C')
	{
		game->map->maps[game->player->y][game->player->x] = '0';
		game->player->get_cheese += 1;
	}
}

int	ft_check_e(t_game *game, int y, int x)
{
	if (game->map->maps[y][x] == 'E')
	{
		if (game->player->get_cheese == game->map->nb_c)
		{
			ft_printf("You won !\nYou get %d cheese(s) with %d move(s)\n",
				game->player->get_cheese,
				game->player->nbr_count);
			ft_destroy(game);
		}
		else
			return (TRUE);
	}
	return (FALSE);
}

void	ft_anti_afk(t_game *game)
{
	if (game->player->move == FALSE)
	{
		if (game->player->anti_afk == -1)
			ft_printf("[ANTI-AFK]\nINIT\n");
		else if (game->player->anti_afk == 1000)
			ft_printf("[ANTI-AFK]\nAre you alive ? Move if you want to live !\n");
		else if (game->player->anti_afk == 4000)
		{
			ft_printf("[ANTI-AFK]\nToo long AFK: CLOSE THE GAME\n");
			ft_destroy(game);
		}
	}
	game->player->anti_afk++;
}

void	ft_init_player(t_game *game)
{
	game->player = (t_player *)malloc(sizeof(t_player));
	if (!game->player)
		return ;
	game->player->move = FALSE;
	game->player->nbr_count = 0;
	game->player->x = 0;
	game->player->y = 0;
	game->player->anim_count = 20000;
	game->player->anti_afk = -1;
	game->player->get_cheese = 0;
	game->player->can_exit = FALSE;
	return ;
}
