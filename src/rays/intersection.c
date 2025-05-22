/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:54:22 by msavelie          #+#    #+#             */
/*   Updated: 2025/05/18 16:51:23 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

static void	check_nearest_intersection(t_hit *hit_arr[2], t_obj **object,
	t_obj *new_obj, float *tnear)
{
	if (hit_arr[0]->t0 < 0)
		hit_arr[0]->t0 = hit_arr[0]->t1;
	if (hit_arr[0]->t0 > EPSILON && hit_arr[0]->t0 < *tnear)
	{
		*tnear = hit_arr[0]->t0;
		*object = new_obj;
		*(hit_arr[1]) = *(hit_arr[0]);
	}
}

t_obj	*check_obj_intersection(t_rt *rt, t_ray ray,
	t_hit *hit_arr[2], float *tnear)
{
	t_obj	*object;
	bool	hit;
	int		i;

	hit = false;
	object = NULL;
	i = 0;
	while (i < rt->obj_count)
	{
		hit_arr[0]->temp_part = -1;
		hit_arr[0]->t0 = INFINITY;
		hit_arr[0]->t1 = INFINITY;
		hit = check_intersection(ray, rt->objects[i], hit_arr[0]);
		if (hit)
		{
			check_nearest_intersection(hit_arr, &object,
				&rt->objects[i], tnear);
		}
		i++;
	}
	return (object);
}

static void	set_hit_interval(t_hit *hit_info, float tca,
	float radius2, float d2)
{
	float	thc;

	thc = sqrt(radius2 - d2);
	hit_info->t0 = tca - thc;
	hit_info->t1 = tca + thc;
}

bool	intersect_sphere(t_ray ray, t_obj sphere, t_hit *hit_info)
{
	float		radius2;
	t_vector	center;
	t_vector	ray_length;
	float		tca;
	float		d2;

	radius2 = pow(sphere.diameter / 2, 2);
	center = sphere.coords;
	ray_length = vec_sub(center, ray.orig);
	tca = dot(ray_length, ray.dir);
	d2 = dot(ray_length, ray_length) - tca * tca;
	if (d2 > radius2)
		return (false);
	set_hit_interval(hit_info, tca, radius2, d2);
	hit_info->phit = vec_add(ray.orig, vec_mul_num(ray.dir, hit_info->t0));
	hit_info->nhit = vec_sub(hit_info->phit, center);
	normalize(&hit_info->nhit);
	if (dot(ray.dir, hit_info->nhit) > 0)
		hit_info->nhit = vec_mul_num(hit_info->nhit, -1);
	return (true);
}

bool	intersect_plane(t_ray ray, t_obj plane, float *t)
{
	float		denom;
	t_vector	diff;
	float		temp_t;

	denom = dot(ray.dir, plane.normalized);
	if (fabsl(denom) > 1e-6)
	{
		diff = vec_sub(plane.coords, ray.orig);
		temp_t = dot(diff, plane.normalized) / denom;
		if (temp_t > BIAS)
		{
			*t = temp_t;
			return (true);
		}
	}
	return (false);
}
