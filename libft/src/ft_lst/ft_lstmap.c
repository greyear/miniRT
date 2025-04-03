/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:24:34 by azinchen          #+#    #+#             */
/*   Updated: 2024/07/26 13:59:50 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*cur_list;
	t_list	*res_list;
	void	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	res_list = NULL;
	while (lst != NULL)
	{
		new_content = f(lst->content);
		if (!new_content)
			return (NULL);
		cur_list = ft_lstnew(new_content);
		if (!cur_list)
		{
			ft_lstclear(&res_list, del);
			del(new_content);
			return (NULL);
		}
		ft_lstadd_back(&res_list, cur_list);
		lst = lst->next;
	}
	return (res_list);
}
