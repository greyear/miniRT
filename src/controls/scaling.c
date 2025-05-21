/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:15:16 by azinchen          #+#    #+#             */
/*   Updated: 2025/05/21 13:15:17 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

static float	float_add(float fl1, float fl2)
{
	float	res;

	res = fl1 + fl2;
	if (res >= 0.00001f)
		return (res);
	else
		return (0.0f);
}

void	scale(t_rt *rt, mlx_key_data_t keydata, t_vector del) //set limits?
{
	if (rt->obj_sel == OBJ_SEL)
	{
		if (rt->objects[rt->obj_index].type == SPHERE)
		{
			if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_DOWN)
				rt->objects[rt->obj_index].diameter
					= float_add(rt->objects[rt->obj_index].diameter, del.y);
		}
		if (rt->objects[rt->obj_index].type == CYLINDER)
		{
			if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_RIGHT)
				rt->objects[rt->obj_index].radius
					= float_add(rt->objects[rt->obj_index].radius, del.x / 2);
			else if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_DOWN)
				rt->objects[rt->obj_index].height
					= float_add(rt->objects[rt->obj_index].height, del.y);
		}
	}
	else if (rt->obj_sel == LIGHT_SEL)
		return ;
	else if (rt->obj_sel == CAMERA_SEL)
		return ;
}
