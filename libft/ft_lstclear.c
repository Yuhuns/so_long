/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 15:53:36 by awallet           #+#    #+#             */
/*   Updated: 2022/05/12 11:31:41 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp_list;

	if (!lst || !del || !(*lst))
		return ;
	while (*lst)
	{
		del((*lst)->content);
		temp_list = *lst;
		*lst = temp_list->next;
		free(temp_list);
	}
	*lst = NULL;
}
