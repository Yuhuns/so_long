/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 16:34:57 by awallet           #+#    #+#             */
/*   Updated: 2022/05/12 20:06:53 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *src, int c)
{
	if (!src)
		return (NULL);
	while (*src != (unsigned char)c)
	{
		if (!(*src))
			return (NULL);
		src++;
	}
	return ((char *)src);
}
