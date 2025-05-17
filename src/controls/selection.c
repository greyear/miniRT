/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 11:54:56 by msavelie          #+#    #+#             */
/*   Updated: 2025/05/17 15:27:23 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

void	select_objects(t_rt *rt)
{
	rt->obj_sel = OBJ_SEL;
	if (rt->obj_count == 1)
		return ;
	else if (rt->obj_index < rt->obj_count - 1)
		rt->obj_index++;
	else
		rt->obj_index = 0;
	draw_gui(rt);
}
