/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:54:22 by msavelie          #+#    #+#             */
/*   Updated: 2025/04/24 16:10:00 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

bool	intersect_sphere(t_vector rayorig, t_vector raydir, t_obj sphere, float *t0, float *t1)
{
	float		radius2 = pow(sphere.diameter / 2, 2);
	t_vector	center = sphere.coordinates;
	t_vector	ray_length = vec_sub(center, rayorig);
	float		tca = ray_length.x * raydir.x + ray_length.y * raydir.y + ray_length.z * raydir.z;
	// if (tca < 0)
	// 	return (false);
	float		d2 = pow(ray_length.x, 2) + pow(ray_length.y, 2) + pow(ray_length.z, 2) - tca * tca;
	if (d2 > radius2)
		return false;
	float thc = sqrt(radius2 - d2);
	*t0 = tca - thc;
	*t1 = tca + thc;
	return (true);
}

bool	intersect_cylinder(t_vector rayorig, t_vector raydir, t_obj cylinder, float *t_hit, int *hit_part)
{
	*t_hit = INFINITY;
	*hit_part = -1;

	t_vector	oc = vec_sub(rayorig, cylinder.coordinates);
	float		dir_dot_axis = dot(raydir, cylinder.normalized);
	t_vector	ray_perp_dir = vec_sub(raydir, vec_mul_num(cylinder.normalized, dir_dot_axis));
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

			t_vector	intersection = vec_add(rayorig, vec_mul_num(raydir, t_candidate));
			t_vector	to_point = vec_sub(intersection, cylinder.coordinates);
			float		height = dot(to_point, cylinder.normalized);

			if (height >= 0.0f && height <= cylinder.height && t_candidate < *t_hit)
			{
				*t_hit = t_candidate;
				*hit_part = 0;
			}
		}
	}

	for (int cap = 0; cap < 2; ++cap) {
		float	cap_offset = (cap == 0) ? 0.0f : cylinder.height;
		t_vector cap_center = vec_add(cylinder.coordinates, vec_mul_num(cylinder.normalized, cap_offset));

		float	ray_dot_axis = dot(raydir, cylinder.normalized);
		if (fabsf(ray_dot_axis) < 1e-6f)
			continue;

		float	t_intersection = dot(vec_sub(cap_center, rayorig), cylinder.normalized) / ray_dot_axis;
		if (t_intersection < 0.0f || t_intersection > *t_hit)
			continue;

		t_vector	intersection = vec_add(rayorig, vec_mul_num(raydir, t_intersection));
		t_vector	to_center = vec_sub(intersection, cap_center);

		if (dot(to_center, to_center) <= cylinder.radius * cylinder.radius)
		{
			*t_hit = t_intersection;
			*hit_part = (cap == 0) ? 1 : 2;
		}
	}

	return (*hit_part != -1);
}


