/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:24:35 by msavelie          #+#    #+#             */
/*   Updated: 2025/05/24 15:14:20 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

static bool	set_plane_shadow(t_ray light_ray, t_rt *rt,
	t_hit *hit_info, t_obj object)
{
	float		t;
	t_vector	hit_point;
	t_vector	to_light;
	t_vector	to_hit;

	if (intersect_plane(light_ray, object, &t) && t > BIAS)
	{
		hit_point = vec_add(light_ray.orig, vec_mul_num(light_ray.dir, t));
		to_light = vec_sub(rt->light.coords, light_ray.orig);
		to_hit = vec_sub(hit_point, light_ray.orig);
		if (vec_length(to_hit) < vec_length(to_light) - EPSILON)
		{
			hit_info->t0 = t;
			hit_info->phit = hit_point;
			return (true);
		}
	}
	return (false);
}

static bool	check_shadow(t_rt *rt, t_obj object,
	t_ray light_ray, t_hit *hit_info)
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

static bool	is_correct_distance(t_rt *rt, t_hit *hit_info, t_hit tmp_hit)
{
	t_vector	to_light;
	float		dist_to_light;
	t_vector	hit_to_obj;
	float		dist_to_obj;

	to_light = vec_sub(rt->light.coords, hit_info->phit);
	dist_to_light = vec_length(to_light);
	hit_to_obj = vec_sub(tmp_hit.phit, hit_info->phit);
	dist_to_obj = vec_length(hit_to_obj);
	if (dist_to_obj > dist_to_light + EPSILON)
		return (false);
	return (true);
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
		tmp_hit = (t_hit){0};
		shadow_hit = check_shadow(rt, rt->objects[i], light_ray, &tmp_hit);
		if (shadow_hit && is_correct_distance(rt, hit_info, tmp_hit))
		{
			transmission = (t_vector){0, 0, 0};
			break ;
		}
	}
	return (transmission);
}
