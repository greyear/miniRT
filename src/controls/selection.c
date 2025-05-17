/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 11:54:56 by msavelie          #+#    #+#             */
/*   Updated: 2025/05/17 16:29:03 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

void	select_objects(t_rt *rt)
{
	rt->needs_render = 2;
	if (rt->obj_sel != OBJ_SEL)
	{
		rt->obj_index = 0;
		rt->obj_sel = OBJ_SEL;
		return ;
	}
	if (rt->obj_count == 1)
		return ;
	else if (rt->obj_index < rt->obj_count - 1)
		rt->obj_index++;
	else
		rt->obj_index = 0;
	rt->obj_sel = OBJ_SEL;
}

void	select_light(t_rt *rt)
{
	rt->needs_render = 2;
	rt->obj_sel = LIGHT_SEL;
}

void	select_camera(t_rt *rt)
{
	rt->needs_render = 2;
	rt->obj_sel = CAMERA_SEL;
}
