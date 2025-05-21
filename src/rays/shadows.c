/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:24:35 by msavelie          #+#    #+#             */
/*   Updated: 2025/05/21 20:14:45 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

// static bool	set_plane_shadow(t_ray light_ray, t_rt *rt,
// 	t_hit *hit_info, t_obj object)
// {
// 	float		t;
// 	bool		shadow_hit;
// 	t_vector	hit_point;
// 	t_vector	light_to_hit;
// 	t_vector	point_to_hit;

// 	shadow_hit = false;
// 	if (intersect_plane(light_ray, object, &t) && t > BIAS)
// 	{
// 		hit_point = vec_add(light_ray.orig, vec_mul_num(light_ray.dest, t));
// 		light_to_hit = vec_sub(hit_point, rt->light.coords);
// 		point_to_hit = vec_sub(hit_point, hit_info->phit);
// 		if (dot(light_to_hit, object.normalized)
// 			* dot(point_to_hit, object.normalized) < 0)
// 		{
// 			hit_info->t0 = t;
// 			shadow_hit = true;
// 		}
// 	}
// 	return (shadow_hit);
// }

static float vec_length(t_vector v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

static bool	set_plane_shadow(t_ray light_ray, t_rt *rt,
	t_hit *hit_info, t_obj object)
{
	float		t;
	float		light_dist;
	bool		shadow_hit;
	float		dist_from_light;
	//t_vector	light_dir;

	shadow_hit = false;
	dist_from_light = dot(vec_sub(rt->light.coords, object.coords), object.normalized);
	if (fabs(dist_from_light) < 1e-4)
		return false;

	// Новый блок: проверить, находится ли свет на "другой стороне" плоскости
	t_vector hit_to_light = vec_sub(rt->light.coords, hit_info->phit);
	if (dot(hit_to_light, object.normalized) < 0)
		return false;

	light_dist = vec_length(hit_to_light);
	if (intersect_plane(light_ray, object, &t) && t > BIAS && t < light_dist)
	{
		hit_info->t0 = t;
		shadow_hit = true;
	}
	return (shadow_hit);
}

bool	check_shadow(t_rt *rt, t_obj object, t_ray light_ray, t_hit *hit_info)
{
	bool	shadow_hit;

	shadow_hit = false;
	if (object.type == SPHERE)
		shadow_hit = (intersect_sphere(light_ray, object, hit_info)
				&& hit_info->t0 > 0);
	else if (object.type == CYLINDER)
		shadow_hit = (intersect_cylinder(light_ray, object, hit_info,
					&hit_info->hit_part) && hit_info->t0 > 0);
	else if (object.type == PLANE)
		shadow_hit = set_plane_shadow(light_ray, rt, hit_info, object);
	return (shadow_hit);
}

t_vector	calculate_shadows(t_rt *rt, t_obj *object,
	t_hit *hit_info, t_ray light_ray)
{
	t_vector	transmission;
	int			i;
	bool		shadow_hit;
	t_hit		tmp_hit;

	transmission = (t_vector){1, 1, 1};
	light_ray.orig = vec_add(hit_info->phit,
			vec_mul_num(hit_info->nhit, BIAS));
	i = -1;
	while (++i < rt->obj_count)
	{
		if (&rt->objects[i] == object)
			continue ;
		tmp_hit.t0 = 0;
		shadow_hit = check_shadow(rt, rt->objects[i], light_ray, &tmp_hit);
		if (shadow_hit && tmp_hit.t0 > BIAS)
		{
			transmission = (t_vector){0, 0, 0};
			break ;
		}
	}
	return (transmission);
}
