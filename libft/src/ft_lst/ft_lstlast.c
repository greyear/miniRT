/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:48:30 by azinchen          #+#    #+#             */
/*   Updated: 2024/07/26 13:59:34 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*cur_list;

	if (!lst)
		return (NULL);
	cur_list = lst;
	while (cur_list->next != NULL)
		cur_list = cur_list->next;
	return (cur_list);
}
