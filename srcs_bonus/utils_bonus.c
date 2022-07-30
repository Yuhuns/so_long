/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 01:01:19 by awallet           #+#    #+#             */
/*   Updated: 2022/07/30 20:41:56 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	ft_strlen_sl(char *line)
{
	int	i;

	i = 0;
	while (line && line[i] && line[i] != '\n')
		i++;
	return (i);
}

char	*ft_strjoin_sl(char *s1, char *s2, char charset)
{
	char	*result;
	int		i;
	int		size;

	size = (ft_strlen_sl(s1) + ft_strlen_sl(s2));
	result = ft_calloc(size + 2, sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (*s2)
	{
		result[i] = *s2++;
		i++;
	}
	result[size] = charset;
	result[size + 1] = '\0';
	if (s1)
		free(s1);
	return (result);
}
