/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:25:07 by azinchen          #+#    #+#             */
/*   Updated: 2024/07/26 13:59:22 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*cur_list;

	if (!lst || !f)
		return ;
	cur_list = lst;
	while (cur_list != NULL)
	{
		f(cur_list->content);
		cur_list = cur_list->next;
	}
}
