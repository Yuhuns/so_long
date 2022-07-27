/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:35:16 by awallet           #+#    #+#             */
/*   Updated: 2022/05/12 13:05:42 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*newchar;
	size_t	len_check;
	size_t	alloc_size;

	if (!s)
		return (NULL);
	len_check = ft_strlen(s);
	if (start > len_check)
	{
		newchar = malloc(1 * sizeof(char));
		if (!newchar)
			return (NULL);
		*newchar = '\0';
		return (newchar);
	}
	if (len_check - start < len)
		alloc_size = len_check - start + 1;
	else
		alloc_size = len + 1;
	newchar = ft_calloc(alloc_size, sizeof(char));
	if (!newchar)
		return (NULL);
	ft_strlcpy(newchar, s + start, len + 1);
	return (newchar);
}
