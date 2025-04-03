/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:42:54 by azinchen          #+#    #+#             */
/*   Updated: 2024/07/26 14:00:00 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*res_list;

	res_list = (t_list *)malloc(sizeof(t_list));
	if (!res_list)
		return (NULL);
	res_list->content = content;
	res_list->next = NULL;
	return (res_list);
}
