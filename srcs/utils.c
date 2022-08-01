/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 01:01:19 by awallet           #+#    #+#             */
/*   Updated: 2022/08/01 15:59:37 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_put_data_bis(t_game *game, int y, int x, int id)
{
	if (game->map.maps[y][x] == 'P')
		ft_player_data(game, x, y, id);
}

void	ft_arounded_wall(t_game *game, int y, int x)
{
	if (game->map.maps[y - 1][x] == '1'
		&& game->map.maps[y + 1][x] == '1'
		&& game->map.maps[y][x - 1] == '1'
		&& game->map.maps[y][x + 1] == '1')
	{
		ft_printf("GAME OVER\nBlocked by 4 walls...\n");
		ft_destroy(game);
	}
}

int	ft_strlen_sl(char *line)
{
	int	i;

	i = 0;
	while (line && line[i] && line[i] != '\n')
		i++;
	return (i);
}

char	*ft_strjoin_sl(char *s1, char *s2, char charset)
{
	char	*result;
	int		i;
	int		size;

	size = (ft_strlen_sl(s1) + ft_strlen_sl(s2));
	result = ft_calloc(size + 2, sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (*s2)
	{
		result[i] = *s2++;
		i++;
	}
	result[size] = charset;
	result[size + 1] = '\0';
	if (s1)
		free(s1);
	return (result);
}
