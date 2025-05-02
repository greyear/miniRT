/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:54:22 by msavelie          #+#    #+#             */
/*   Updated: 2025/05/02 16:21:58 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

t_obj	*check_obj_intersection(t_rt *rt, t_ray ray, t_hit *hit_arr[2], float *tnear)
{
	t_obj	*object;
	bool	hit;
	int		i;

	hit = false;
	object = NULL;
	i = 0;
	while (i < rt->obj_count) {
		hit_arr[0]->temp_part = -1;
		hit_arr[0]->t0 = INFINITY;
		hit_arr[0]->t1 = INFINITY;
		hit = check_intersection(ray, rt->objects[i], hit_arr[0]);
		if (hit) {
			if (hit_arr[0]->t0 < 0) hit_arr[0]->t0 = hit_arr[0]->t1;
			if (hit_arr[0]->t0 < *tnear) {
				*tnear = hit_arr[0]->t0;
				object = &rt->objects[i];
				*(hit_arr[1]) = *(hit_arr[0]);
			}
		}
		i++;
	}
	return (object);
}

bool	intersect_sphere(t_ray ray, t_obj sphere, t_hit *hit_info)
{
	float		radius2 = pow(sphere.diameter / 2, 2);
	t_vector	center = sphere.coordinates;
	t_vector	ray_length = vec_sub(center, ray.origin);
	float		tca = ray_length.x * ray.destination.x + ray_length.y * ray.destination.y + ray_length.z * ray.destination.z;
	// return if camera is inside an object
	// if (tca < 0)
	// 	return (false);
	float		d2 = pow(ray_length.x, 2) + pow(ray_length.y, 2) + pow(ray_length.z, 2) - tca * tca;
	if (d2 > radius2)
		return false;
	float thc = sqrt(radius2 - d2);
	hit_info->t0 = tca - thc;
	hit_info->t1 = tca + thc;
	return (true);
}

bool	intersect_plane(t_ray ray, t_obj plane, float *t)
{
	float		denom;
	t_vector	diff;
	float		temp_t;

	denom = dot(ray.destination, plane.normalized);
	if (fabsf(denom) > 1e-6f)
	{
		diff = vec_sub(plane.coordinates, ray.origin);
		temp_t = dot(diff, plane.normalized) / denom;
		if (temp_t >= 0)
		{
			*t = temp_t;
			return (true);
		}
	}
	return (false);
}
