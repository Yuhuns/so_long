/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:05:00 by awallet           #+#    #+#             */
/*   Updated: 2022/05/13 13:59:42 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static int	ft_length_word(const char *s, char c)
{
	int		length;

	length = 0;
	while (*s && *s != c)
	{
		length++;
		s++;
	}
	return (length);
}

static char	**ft_free(char **tab, int i)
{
	while (i--)
		free(tab[i]);
	free(tab);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	char	**tab;
	int		i;
	int		nbword;

	i = 0;
	if (!s)
		return (NULL);
	nbword = ft_count_word(s, c);
	tab = ft_calloc(nbword + 1, sizeof(char *));
	if (!tab)
		return (NULL);
	while (nbword--)
	{
		while (*s && *s == c)
			s++;
		tab[i] = ft_substr(s, 0, ft_length_word(s, c));
		if (!tab[i])
			return (ft_free(tab, i));
		s += ft_length_word(s, c);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
