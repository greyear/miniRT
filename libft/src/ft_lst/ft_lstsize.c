/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:41:57 by azinchen          #+#    #+#             */
/*   Updated: 2024/07/26 14:00:12 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_lstsize(t_list *lst)
{
	int		len;
	t_list	*cur_list;

	if (!lst)
		return (0);
	cur_list = lst;
	len = 0;
	while (cur_list != NULL)
	{
		cur_list = cur_list->next;
		len++;
	}
	return (len);
}
