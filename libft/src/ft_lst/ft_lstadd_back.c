/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 20:30:07 by azinchen          #+#    #+#             */
/*   Updated: 2024/07/26 13:58:25 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_list;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last_list = ft_lstlast(*lst);
	last_list->next = new;
}
