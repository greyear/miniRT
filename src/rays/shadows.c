/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:24:35 by msavelie          #+#    #+#             */
/*   Updated: 2025/05/12 15:20:57 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

bool	check_shadow(t_rt *rt, t_obj object, t_ray light_ray, t_hit *hit_info)
{
	bool	shadow_hit;
	float	pl_side_phit;
	float	pl_side_light;

	shadow_hit = false;
	if (object.type == SPHERE)
		shadow_hit = intersect_sphere(light_ray, object, hit_info) && hit_info->t0 > 0;
	else if (object.type == CYLINDER)
		shadow_hit = intersect_cylinder(light_ray, object, hit_info, &hit_info->hit_part) && hit_info->t0 > 0;
	else if (object.type == PLANE)
	{
		pl_side_phit = dot(vec_sub(hit_info->phit, object.coordinates), object.normalized);
		pl_side_light = dot(vec_sub(rt->light->coordinates, object.coordinates), object.normalized);
		if (pl_side_phit * pl_side_light < 0.0f)
			shadow_hit = intersect_plane(light_ray, object, &hit_info->t0) && hit_info->t0 > 0;
	}
	return (shadow_hit);
}

t_vector	calculate_shadows(t_rt *rt, t_obj *object, t_hit *hit_info, t_ray light_ray)
{
	t_vector	transmission;
	int			i;
	bool		shadow_hit;

	transmission = (t_vector){1, 1, 1};
	i = -1;
	while (i < rt->obj_count)
	{
		++i;
		if (&rt->objects[i] == object)
			continue;
		hit_info->t0 = 0;
		hit_info->t1 = 0;
		hit_info->temp_part = -1;
		light_ray.origin = vec_add(hit_info->phit, vec_mul_num(hit_info->nhit, BIAS));
		//light_ray.origin = vec_add(hit_info->phit, vec_mul_num(light_ray.destination, BIAS));
		shadow_hit = check_shadow(rt, rt->objects[i], light_ray, hit_info);
		if (shadow_hit) {
			transmission = (t_vector){0, 0, 0};
			break;
		}
	}
	return (transmission);
}
