/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:39:08 by awallet           #+#    #+#             */
/*   Updated: 2022/07/26 21:30:17 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static int	ft_format(va_list *args, const char format)
{
	int		len;

	len = 0;
	if (format == 's')
		len += ft_print_putstr_fd(va_arg(*args, char *), 1);
	else if (format == 'c')
		len += ft_print_putchar_fd(va_arg(*args, int), 1);
	else if (format == 'i' || format == 'd')
		len += ft_print_nbr(va_arg(*args, int), 1);
	else if (format == 'p')
		len += ft_print_ptr(va_arg(*args, unsigned long int), LIT, 1);
	else if (format == 'u')
		len += ft_print_base(va_arg(*args, unsigned int), NUM, 10, 1);
	else if (format == 'x')
		len += ft_print_base(va_arg(*args, unsigned int), LIT, 16, 1);
	else if (format == 'X')
		len += ft_print_base(va_arg(*args, unsigned int), BIG, 16, 1);
	else if (format == '%')
		len += ft_print_putchar_fd('%', 1);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			len += ft_format(&args, *(str + 1));
			str++;
		}
		else
			len += ft_print_putchar_fd(*str, 1);
		str++;
	}
	va_end(args);
	return (len);
}
