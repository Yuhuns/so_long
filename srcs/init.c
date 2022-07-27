/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 05:14:14 by awallet           #+#    #+#             */
/*   Updated: 2022/07/27 17:30:08 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_init_game(char *map)
{
	t_game	*game;

	if (!IS_APPLE)
	{
		game = (t_game *)malloc(sizeof(t_game));
		if (!game)
			return ;
		game->map = NULL;
		game->player = NULL;
		ft_init_map(map, game);
		ft_init_player(game);
		ft_init_mlx(game);
	}
	else
		ft_printf("Error\nThe game is not compatible with apple devices !\n");
}
