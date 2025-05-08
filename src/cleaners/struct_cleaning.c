/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_cleaning.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:11:30 by azinchen          #+#    #+#             */
/*   Updated: 2025/04/09 14:17:18 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

void	struct_clean(t_miniRT *rt)
{
	//another fields
	if (rt->objects)
	{
		//object_clean(rt);
		free(rt->objects);
	}
	if (rt->fd >= 0)
		close(rt->fd);
	/*if (rt)
		free(rt); as we're not allocating rt in main, but just have it in stack*/ 
}
