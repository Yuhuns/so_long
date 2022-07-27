/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:02:01 by awallet           #+#    #+#             */
/*   Updated: 2022/07/26 21:30:09 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_putstr_fd(char *s, int fd)
{
	int	len;

	len = 0;
	if (!s)
		return (write(fd, "(null)", 6));
	while (*s)
		len += write(fd, s++, 1);
	return (len);
}

int	ft_print_putchar_fd(int c, int fd)
{
	write(fd, &c, 1);
	return (1);
}
