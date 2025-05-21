/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:22:38 by azinchen          #+#    #+#             */
/*   Updated: 2025/05/20 14:54:56 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

void	move(t_rt *rt, t_vector change) //limits? //try to push to the side
{
	t_vector	forward;
	t_vector	right;
	t_vector	up;
	t_vector	up_guess;
	t_vector	world_change;

	forward = normalize_return(rt->camera.normalized);
	up_guess = (t_vector){0, 1, 0};
	if (fabs(dot_product(forward, up_guess)) > 0.99)
		up_guess = (t_vector){1, 0, 0};
	right = normalize_return(cross_product(up_guess, forward));
	up = cross_product(forward, right);
	world_change = vec_add(vec_add(vec_mul_num(right, change.x),
				vec_mul_num(up, change.y)), vec_mul_num(forward, change.z));
	if (rt->obj_sel == OBJ_SEL)
		rt->objects[rt->obj_index].coords
			= vec_add(rt->objects[rt->obj_index].coords, world_change);
	else if (rt->obj_sel == LIGHT_SEL)
		rt->light.coords = vec_add(rt->light.coords, world_change);
	else if (rt->obj_sel == CAMERA_SEL)
		rt->camera.coords = vec_add(rt->camera.coords, world_change);
}
