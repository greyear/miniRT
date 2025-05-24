/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_caps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 16:10:08 by msavelie          #+#    #+#             */
/*   Updated: 2025/05/24 15:20:19 by msavelie         ###   ########.fr       */
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

static t_vector	calc_cap_center(t_obj cylinder, int cap)
{
	t_vector	cap_center;
	t_vector	normalized_cap_offset;

	normalized_cap_offset = vec_mul_num(cylinder.normalized,
			calc_cap_offset(cylinder, cap));
	cap_center = vec_add(cylinder.coords, normalized_cap_offset);
	return (cap_center);
}

static void	write_cap_info(t_hit *hit_info, t_ray ray, float t_intersection)
{
	hit_info->t0 = t_intersection;
	hit_info->phit = vec_add(ray.orig,
			vec_mul_num(ray.dir, t_intersection));
}

void	check_caps_intersection(t_obj cylinder, t_hit *hit_info,
	t_ray ray, int *hit_part)
{
	int			cap;
	t_vector	cap_center;
	float		ray_dot_axis;
	float		t_intersection;
	t_vector	to_center;

	cap = -1;
	while (++cap < 2)
	{
		cap_center = calc_cap_center(cylinder, cap);
		ray_dot_axis = dot(ray.dir, cylinder.normalized);
		if (fabsl(ray_dot_axis) < 1e-6)
			continue ;
		t_intersection = dot(vec_sub(cap_center, ray.orig),
				cylinder.normalized) / ray_dot_axis;
		if (t_intersection < 0.0f || t_intersection > hit_info->t0)
			continue ;
		to_center = vec_sub(vec_add(ray.orig,
					vec_mul_num(ray.dir, t_intersection)), cap_center);
		if (dot(to_center, to_center) <= pow(cylinder.radius, 2))
		{
			write_cap_info(hit_info, ray, t_intersection);
			calc_hit_part(cap, hit_part);
		}
	}
}
