/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:14:55 by azinchen          #+#    #+#             */
/*   Updated: 2025/05/21 13:14:57 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

static void	rotate_camera(t_rt *rt, mlx_key_data_t keydata,
	t_vector rotation_vec)
{
	float	angle;

	if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_RIGHT)
	{
		angle = rotation_vec.x / 10;
		rotate_y(&(rt->camera.normalized), angle);
	}
	else if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_DOWN)
	{
		angle = rotation_vec.y / 10;
		rotate_x(&(rt->camera.normalized), angle);
	}
	else if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_D)
	{
		angle = rotation_vec.z / 10;
		rotate_z(&(rt->camera.normalized), angle);
	}
	normalize(&rt->camera.normalized);
}

static void	rotate_object(t_rt *rt, mlx_key_data_t keydata,
	t_vector rotation_vec)
{
	float	angle;

	if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_RIGHT)
	{
		angle = rotation_vec.x / 10;
		rotate_y(&(rt->objects[rt->obj_index].normalized), angle);
	}
	else if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_DOWN)
	{
		angle = rotation_vec.y / 10;
		rotate_x(&(rt->objects[rt->obj_index].normalized), angle);
	}
	else if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_D)
	{
		angle = rotation_vec.z / 10;
		rotate_z(&(rt->objects[rt->obj_index].normalized), angle);
	}
	normalize(&rt->objects[rt->obj_index].normalized);
}

void	rotate(t_rt *rt, mlx_key_data_t keydata, t_vector rotation_vec)
{
	if (rt->obj_sel == OBJ_SEL)
	{
		if (rt->objects[rt->obj_index].type == SPHERE)
			return ;
		if (rt->objects[rt->obj_index].type == CYLINDER)
			rotate_object(rt, keydata, rotation_vec);
		if (rt->objects[rt->obj_index].type == PLANE)
			rotate_object(rt, keydata, rotation_vec);
	}
	else if (rt->obj_sel == LIGHT_SEL)
		return ;
	else if (rt->obj_sel == CAMERA_SEL) //what if 0:0:0 as a start?
		rotate_camera(rt, keydata, rotation_vec);
}
