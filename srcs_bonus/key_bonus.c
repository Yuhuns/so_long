/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 22:29:01 by awallet           #+#    #+#             */
/*   Updated: 2022/07/30 20:39:49 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	ft_key(int key, t_game *game)
{
	if (key == W || key == UP)
		ft_move_w(game);
	else if (key == S || key == DOWN)
		ft_move_s(game);
	else if (key == A || key == LEFT)
		ft_move_a(game);
	else if (key == D || key == RIGHT)
		ft_move_d(game);
	if (game->player.move == TRUE)
	{
		game->player.anti_afk = FALSE;
		game->player.move = FALSE;
		ft_printf("Move count : %d\n", game->player.nbr_count);
	}
	return (E_SUCC);
}
