/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:20:41 by msavelie          #+#    #+#             */
/*   Updated: 2025/05/02 16:45:02 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

static inline float	calc_cap_offset(t_obj cylinder, int cap)
{
	if (cap == 0)
		return (0.0f);
	return (cylinder.height);
}

static inline void	calc_hit_part(int cap, int *hit_part)
{
	if (cap == 0)
		*hit_part = 1;
	else
		*hit_part = 2;
}

static void	check_caps_intersection(t_obj cylinder, t_hit *hit_info, t_ray ray, int *hit_part)
{
	int			cap;
	t_vector	cap_center;
	float		ray_dot_axis;
	float		t_intersection;
	t_vector	to_center;

	cap = -1;
	while (cap < 2)
	{
		++cap;
		cap_center = vec_add(cylinder.coordinates, vec_mul_num(cylinder.normalized, calc_cap_offset(cylinder, cap)));
		ray_dot_axis = dot(ray.destination, cylinder.normalized);
		if (fabsf(ray_dot_axis) < 1e-6f)
			continue;
		t_intersection = dot(vec_sub(cap_center, ray.origin), cylinder.normalized) / ray_dot_axis;
		if (t_intersection < 0.0f || t_intersection > hit_info->t0)
			continue;
		to_center = vec_sub(vec_add(ray.origin, vec_mul_num(ray.destination, t_intersection)), cap_center);
		if (dot(to_center, to_center) <= pow(cylinder.radius, 2))
		{
			hit_info->t0 = t_intersection;
			calc_hit_part(cap, hit_part);
		}
	}
}

bool	intersect_cylinder(t_ray ray, t_obj cylinder, t_hit *hit_info, int *hit_part)
{
	hit_info->t0 = INFINITY;
	*hit_part = -1;

	t_vector	oc = vec_sub(ray.origin, cylinder.coordinates);
	t_vector	ray_perp_dir = vec_sub(ray.destination, vec_mul_num(cylinder.normalized, dot(ray.destination, cylinder.normalized)));
	float		ray_perp_len = dot(ray_perp_dir, ray_perp_dir);
	t_vector	oc_proj = vec_sub(oc, vec_mul_num(cylinder.normalized, dot(oc, cylinder.normalized)));

	float	b = 2.0f * dot(ray_perp_dir, oc_proj);

	float	discriminant = b * b - 4 * ray_perp_len * (dot(oc_proj, oc_proj) - cylinder.radius * cylinder.radius);

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
				*hit_part = 0;
			}
		}
	}

	check_caps_intersection(cylinder, hit_info, ray, hit_part);

	return (*hit_part != -1);
}
