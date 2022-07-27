/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 22:49:31 by awallet           #+#    #+#             */
/*   Updated: 2022/07/19 22:49:34 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	index;

	if (!s)
		return (NULL);
	index = ft_strlen(s) + 1;
	while (index)
		if (s[--index] == (unsigned char)c)
			return ((char *)(s + index));
	return (NULL);
}
