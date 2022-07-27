/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 16:34:55 by awallet           #+#    #+#             */
/*   Updated: 2022/05/04 12:51:06 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int val, size_t len)
{
	if (!dest && val == 0 && len == 0)
		return (NULL);
	while (len)
		((unsigned char *)dest)[--len] = val;
	return (dest);
}
