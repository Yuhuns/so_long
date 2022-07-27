/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 16:34:59 by awallet           #+#    #+#             */
/*   Updated: 2022/05/10 19:30:20 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t		i;
	char		*s2;

	if (!s1)
		return (NULL);
	i = -1;
	s2 = ft_calloc(ft_strlen(s1) + 1, sizeof(char));
	if (!s1 || !s2)
		return (NULL);
	while (s1[++i])
	{
		s2[i] = s1[i];
	}
	s2[i] = '\0';
	return (s2);
}
