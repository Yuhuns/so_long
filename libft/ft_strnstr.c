/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 20:35:41 by awallet           #+#    #+#             */
/*   Updated: 2022/05/04 12:31:46 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char	*big, const char *little, size_t len)
{
	size_t	big_len;
	size_t	little_len;

	little_len = ft_strlen(little);
	if (little_len)
	{
		big_len = ft_strlen(big);
		if (len < big_len)
			big_len = len;
		while (big_len >= little_len && ft_strncmp(big, little, little_len))
		{
			big++;
			big_len--;
		}
		if (big_len < little_len)
			return (NULL);
	}
	return ((char *)big);
}
