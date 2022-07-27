/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:53:42 by awallet           #+#    #+#             */
/*   Updated: 2022/07/26 21:30:03 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putptr(unsigned long int n, const char *p, int fd)
{
	int		len;

	len = 0;
	if (n >= 16)
		len += ft_putptr(n / 16, p, fd);
	len += ft_print_putchar_fd(p[n % 16], fd);
	return (len);
}

int	ft_print_ptr(unsigned long int n, const char *p, int fd)
{
	int	len;

	if (!n)
		return (ft_print_putstr_fd(PTR_NULL, 1));
	len = 0;
	len += ft_print_putstr_fd("0x", 1);
	len += ft_putptr(n, p, fd);
	return (len);
}
