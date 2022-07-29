/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 12:31:53 by awallet           #+#    #+#             */
/*   Updated: 2022/07/29 18:38:25 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	main(int ac, char **av)
{
	if (ac == 2)
		ft_init_game(av[1]);
	else
		ft_printf("Error\nMissing somes arguments !\nUse: ./so_long_bonus MAP\n");
}
