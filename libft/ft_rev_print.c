/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:22:36 by awallet           #+#    #+#             */
/*   Updated: 2022/07/26 21:02:45 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_rev_print(char *str)
{
	int	len;
	int	i;

	len = ft_strlen(str) - 1;
	i = -1;
	while (str[++i])
		ft_putchar_fd(str[len--], 1);
}
