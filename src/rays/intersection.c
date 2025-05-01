/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:54:22 by msavelie          #+#    #+#             */
/*   Updated: 2025/05/01 11:00:45 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

// t_obj	*check_obj_intersection(t_rt *rt, t_ray ray, t_obj *objects)
// {
// 	int temp_part = -1;
// 	bool hit = false;
// 	float t0 = INFINITY;
// 	float t1 = INFINITY;
	
// 	for (int i = 0; i < rt->obj_count; i++) {
		
// 		if (objects[i].type == SPHERE)
// 			hit = intersect_sphere(ray.origin, ray.destination, objects[i], &t0, &t1);
// 		else if (objects[i].type == CYLINDER)
// 			hit = intersect_cylinder(ray.origin, ray.destination, objects[i], &t0, &temp_part);
// 		else if (objects[i].type == PLANE)
// 			hit = intersect_plane(ray.origin, ray.destination, objects[i], &t0);

// 		if (hit) {
// 			if (t0 < 0) t0 = t1;
// 			if (t0 < tnear) {
// 				tnear = t0;
// 				hit_part = temp_part;
// 				return (&objects[i]);
// 			}
// 		}
// 	}
// 	return (NULL);
// }

bool	intersect_sphere(t_ray ray, t_obj sphere, t_hit *hit_info)
{
	float		radius2 = pow(sphere.diameter / 2, 2);
	t_vector	center = sphere.coordinates;
	t_vector	ray_length = vec_sub(center, ray.origin);
	float		tca = ray_length.x * ray.destination.x + ray_length.y * ray.destination.y + ray_length.z * ray.destination.z;
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

bool	intersect_cylinder(t_ray ray, t_obj cylinder, t_hit *hit_info)
{
	hit_info->t0 = INFINITY;
	hit_info->hit_part = -1;

	t_vector	oc = vec_sub(ray.origin, cylinder.coordinates);
	float		dir_dot_axis = dot(ray.destination, cylinder.normalized);
	t_vector	ray_perp_dir = vec_sub(ray.destination, vec_mul_num(cylinder.normalized, dir_dot_axis));
	float		ray_perp_len = dot(ray_perp_dir, ray_perp_dir);

	float	oc_dot_axis = dot(oc, cylinder.normalized);
	t_vector	oc_proj = vec_sub(oc, vec_mul_num(cylinder.normalized, oc_dot_axis));

	float	b = 2.0f * dot(ray_perp_dir, oc_proj);
	float	c = dot(oc_proj, oc_proj) - cylinder.radius * cylinder.radius;

	float	discriminant = b * b - 4 * ray_perp_len * c;

	if (discriminant >= 0.0f)
	{
		float	sqrt_disc = sqrtf(discriminant);
		float	t0 = (-b - sqrt_disc) / (2 * ray_perp_len);
		float	t1 = (-b + sqrt_disc) / (2 * ray_perp_len);

		for (int i = 0; i < 2; ++i) {
			float	t_candidate = (i == 0) ? t0 : t1;
			if (t_candidate < 0.0f)
				continue;

			t_vector	intersection = vec_add(ray.origin, vec_mul_num(ray.destination, t_candidate));
			t_vector	to_point = vec_sub(intersection, cylinder.coordinates);
			float		height = dot(to_point, cylinder.normalized);

			if (height >= 0.0f && height <= cylinder.height && t_candidate < hit_info->t0)
			{
				hit_info->t0 = t_candidate;
				hit_info->hit_part = 0;
			}
		}
	}

	for (int cap = 0; cap < 2; ++cap) {
		float	cap_offset = (cap == 0) ? 0.0f : cylinder.height;
		t_vector cap_center = vec_add(cylinder.coordinates, vec_mul_num(cylinder.normalized, cap_offset));

		float	ray_dot_axis = dot(ray.destination, cylinder.normalized);
		if (fabsf(ray_dot_axis) < 1e-6f)
			continue;

		float	t_intersection = dot(vec_sub(cap_center, ray.origin), cylinder.normalized) / ray_dot_axis;
		if (t_intersection < 0.0f || t_intersection > hit_info->t0)
			continue;

		t_vector	intersection = vec_add(ray.origin, vec_mul_num(ray.destination, t_intersection));
		t_vector	to_center = vec_sub(intersection, cap_center);

		if (dot(to_center, to_center) <= cylinder.radius * cylinder.radius)
		{
			hit_info->t0 = t_intersection;
			hit_info->hit_part = (cap == 0) ? 1 : 2;
		}
	}

	return (hit_info->hit_part != -1);
}

bool	intersect_plane(t_ray ray, t_obj plane, float *t)
{
	float	denom = dot(ray.destination, plane.normalized);
	if (fabsf(denom) > 1e-6f)
	{
		t_vector	diff = vec_sub(plane.coordinates, ray.origin);
		float	temp_t = dot(diff, plane.normalized) / denom;
		if (temp_t >= 0)
		{
			*t = temp_t;
			return (true);
		}
	}
	return (false);
}
