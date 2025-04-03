/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:25:46 by azinchen          #+#    #+#             */
/*   Updated: 2024/07/26 13:58:56 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cur_list;

	if (!*lst || !del)
		return ;
	while (*lst)
	{
		cur_list = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = cur_list;
	}
	*lst = NULL;
}
