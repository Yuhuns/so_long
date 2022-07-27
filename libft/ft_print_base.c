/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:31:15 by awallet           #+#    #+#             */
/*   Updated: 2022/07/26 21:29:49 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_base(unsigned int n, const char *p, int base, int fd)
{
	long	nb;
	int		len;

	len = 0;
	nb = n;
	if (nb >= base)
		len += ft_print_base(nb / base, p, base, fd);
	len += ft_print_putchar_fd(p[nb % base], fd);
	return (len);
}
