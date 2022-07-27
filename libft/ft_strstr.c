/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:51:24 by awallet           #+#    #+#             */
/*   Updated: 2022/07/13 14:51:48 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char *str, char *to_find)
{
	char	*s;
	char	*t_f;

	if (!(*to_find))
		return (str);
	while (*str)
	{
		if (*str == *to_find)
		{
			s = str;
			t_f = to_find;
			while (*str == *t_f)
			{
				str++;
				t_f++;
				if (*t_f == '\0')
					return (s);
			}
		}
		else
			str++;
	}
	return (NULL);
}
