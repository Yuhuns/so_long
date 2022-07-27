/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 16:34:34 by awallet           #+#    #+#             */
/*   Updated: 2022/05/10 22:03:57 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*bytes;

	size *= count;
	bytes = malloc(size);
	if (!bytes)
		return (bytes);
	ft_bzero(bytes, size);
	return (bytes);
}
