/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:31:48 by awallet           #+#    #+#             */
/*   Updated: 2022/07/26 21:29:59 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_nbr(int n, int fd)
{
	long	nb;
	int		len;

	len = 0;
	nb = n;
	if (nb < 0)
	{
		len += ft_print_putchar_fd('-', fd);
		nb *= -1;
	}
	if (nb >= 10)
		len += ft_print_nbr(nb / 10, fd);
	len += ft_print_putchar_fd((nb % 10) + '0', fd);
	return (len);
}
