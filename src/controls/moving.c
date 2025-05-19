/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:22:38 by azinchen          #+#    #+#             */
/*   Updated: 2025/05/19 15:22:41 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

void	move(t_rt *rt, t_vector change)
{
	if (rt->obj_sel == OBJ_SEL)
		rt->objects[rt->obj_index].coords = vec_add(rt->objects[rt->obj_index].coords, change);
	else if (rt->obj_sel == LIGHT_SEL)
		rt->light.coords = vec_add(rt->light.coords, change);
	else if (rt->obj_sel == CAMERA_SEL)
		rt->camera.coords = vec_add(rt->camera.coords, change);
}
