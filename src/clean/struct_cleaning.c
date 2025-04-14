/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_cleaning.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:11:30 by azinchen          #+#    #+#             */
/*   Updated: 2025/04/14 15:49:56 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

void	clean_struct(t_miniRT *rt)
{
	if (!rt)
		return ;
	if (rt->objects)
	{
		free(rt->objects);
		rt->objects = NULL;
	}
}
