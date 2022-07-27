/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 21:01:27 by awallet           #+#    #+#             */
/*   Updated: 2022/07/26 21:34:01 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcspn(const char *s, const char *reject)
{
	const char	*s1 = s;
	const char	*s2;

	while (*s1)
	{
		s2 = reject;
		while (*s2)
		{
			if (*s1 == *s2++)
				return (s1 - s);
		}
		s1++;
	}
	return (s1 - s);
}
