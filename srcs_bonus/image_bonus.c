/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 05:14:14 by awallet           #+#    #+#             */
/*   Updated: 2022/07/29 19:12:27 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	ft_put_image(t_game *game, char *path, int id, char type)
{
	char	*path2;

	path2 = ft_strjoin(path, ".xpm");
	if (type == 'P')
		game->player->sprite[id] = mlx_xpm_file_to_image(game->mlx,
				path2,
				&game->img_size,
				&game->img_size);
	else if (type == 'E')
		game->map->exit = mlx_xpm_file_to_image(game->mlx,
				path2,
				&game->img_size,
				&game->img_size);
	else if (type == 'C')
		game->map->collectable = mlx_xpm_file_to_image(game->mlx,
				path2,
				&game->img_size,
				&game->img_size);
	else if (type == '1')
		game->map->wall = mlx_xpm_file_to_image(game->mlx,
				path2,
				&game->img_size,
				&game->img_size);
	ft_put_enemy_image(game, path2, id, type);
	free(path2);
}

static void	ft_game_img(t_game *game, char *anim, int nbr_image, char type)
{
	char		*ide;
	char		*path;
	int			id;

	id = -1;
	while (++id < nbr_image)
	{
		ide = ft_itoa(id);
		path = ft_strjoin(anim, ide);
		ft_put_image(game, path, id, type);
		free(path);
		free(ide);
	}
}

void	ft_init_image(t_game *game)
{
	ft_game_img(game, "./assets/p/", 11, 'P');
	ft_game_img(game, "./assets/k/", 11, 'K');
	ft_game_img(game, "./assets/w/", 1, '1');
	ft_game_img(game, "./assets/c/", 1, 'C');
	ft_game_img(game, "./assets/e/", 1, 'E');
}
