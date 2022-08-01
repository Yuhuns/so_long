/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 05:10:54 by awallet           #+#    #+#             */
/*   Updated: 2022/08/01 17:27:44 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	ft_read_map(int fd, t_game *game)
{
	char	*map_line;
	char	*line;
	int		nbr_line;

	nbr_line = -1;
	map_line = NULL;
	line = NULL;
	while (++nbr_line < 100)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[0] == '\n')
			game->map.status = C_BAD_MAP;
		map_line = ft_strjoin_sl(map_line, line, '=');
		free(line);
	}
	game->map.maps = ft_split(map_line, '=');
	free(map_line);
}

void	ft_map_size(t_game *game, char *line, int type)
{
	if (type == T_SIZE_LINE)
	{
		if (game->map.width != ft_strlen_sl(line))
			ft_close(game, C_BAD_MAP_SIZE);
	}
	else if (type == T_SIZE_MAP)
	{
		if (((game->map.width * MULT) > MAX_WIDTH
				|| (game->map.heigth * MULT) < MIN_HEIGTH)
			|| ((game->map.width * MULT) < MIN_WIDTH
				|| (game->map.heigth * MULT) > MAX_HEIGTH))
			ft_close(game, C_BAD_MAP);
	}
}

void	ft_check_map_data(t_game *game, char data, int type)
{
	if (type == T_COUNT)
	{
		if (data == '1' || data == '0')
			(void)0;
		else if (data == 'P')
			game->map.nb_p++;
		else if (data == 'E')
			game->map.nb_e++;
		else if (data == 'C')
			game->map.nb_c++;
		else
			ft_close(game, C_BAD_MAP_DATA);
	}
	else if (type == T_MAP)
	{
		if (game->map.nb_p <= 0 || game->map.nb_p >= 2)
			ft_close(game, C_BAD_MAP_COUNT_P);
		else if (game->map.nb_e <= 0 || game->map.nb_e >= 2)
			ft_close(game, C_BAD_MAP_COUNT_E);
		else if (game->map.nb_c <= 0)
			ft_close(game, C_BAD_MAP_COUNT_C);
	}
}

int	ft_check_map(t_game *game)
{
	int	x;
	int	y;

	if (!game->map.maps || game->map.status != C_MAP_OK)
		return (FALSE);
	y = 0;
	game->map.width = ft_strlen_sl(game->map.maps[y]);
	game->map.heigth = 0;
	while (game->map.maps[y])
	{
		x = 0;
		if (game->map.maps[y + 1])
			ft_map_size(game, game->map.maps[y + 1], T_SIZE_LINE);
		while (game->map.maps[y][x])
		{
			ft_check_map_data(game, game->map.maps[y][x],
				T_COUNT);
			x++;
		}	
		y++;
		game->map.heigth++;
	}
	ft_check_map_data(game, 0, T_MAP);
	ft_map_size(game, NULL, T_SIZE_MAP);
	return (TRUE);
}

void	ft_init_map(char *map_file, t_game *game)
{
	int	fd;

	fd = open(map_file, O_RDONLY);
	if (!ft_strstr(map_file, EXT) || fd <= 0)
		ft_close(game, C_BAD_MAP_EXT);
	game->map.nb_c = 0;
	game->map.nb_p = 0;
	game->map.nb_e = 0;
	game->map.status = C_MAP_OK;
	ft_read_map(fd, game);
	if (ft_check_map(game) == FALSE)
		ft_close(game, C_BAD_MAP);
	ft_check_wall(game);
	close(fd);
}
