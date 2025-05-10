/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:20:41 by msavelie          #+#    #+#             */
/*   Updated: 2025/05/05 13:27:29 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

static inline double	calc_cap_offset(t_obj cylinder, int cap)
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
	double		ray_dot_axis;
	double		t_intersection;
	t_vector	to_center;

	cap = -1;
	while (cap < 2)
	{
		++cap;
		cap_center = vec_add(cylinder.coordinates, vec_mul_num(cylinder.normalized, calc_cap_offset(cylinder, cap)));
		ray_dot_axis = dot(ray.destination, cylinder.normalized);
		if (fabsl(ray_dot_axis) < 1e-6f)
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

static void	compute_quadratic_roots(t_cyl_inter *inter_obj, double b)
{
	double	sqrt_disc;

	sqrt_disc = sqrtf(inter_obj->discriminant);
 	inter_obj->t0 = (-b - sqrt_disc) / (2 * inter_obj->ray_perp_len);
 	inter_obj->t1 = (-b + sqrt_disc) / (2 * inter_obj->ray_perp_len);
}

static void	calc_discriminant(t_cyl_inter *inter_obj, t_obj cylinder)
{
	double	b;
 	double	c;

	b = 2.0f * dot(inter_obj->ray_perp_dir, inter_obj->oc_proj);
	c = dot(inter_obj->oc_proj, inter_obj->oc_proj) - cylinder.radius * cylinder.radius;
 	inter_obj->discriminant = b * b - 4 * inter_obj->ray_perp_len * c;
	if (inter_obj->discriminant >= 0.0f)
		compute_quadratic_roots(inter_obj, b);
}

static inline void	set_ray_candidate(t_cyl_inter *inter_obj, int i)
{
	if (i == 0)
		inter_obj->t_candidate = inter_obj->t0;
	else
		inter_obj->t_candidate = inter_obj->t1;
}

static void	check_valid_body_hits(t_cyl_inter *inter_obj, t_ray ray, t_obj cylinder, t_hit *hit_info)
{
	int		i;
	double	height;

	i = -1;
	while (i < 2)
	{
		++i;
 		set_ray_candidate(inter_obj, i);
 		if (inter_obj->t_candidate < 0.0f)
 			continue;
 		inter_obj->intersection = vec_add(ray.origin, vec_mul_num(ray.destination, inter_obj->t_candidate));
 		inter_obj->to_point = vec_sub(inter_obj->intersection, cylinder.coordinates);
 		height = dot(inter_obj->to_point, cylinder.normalized);
 		if (height >= 0.0f && height <= cylinder.height && inter_obj->t_candidate < hit_info->t0)
 		{
 			hit_info->t0 = inter_obj->t_candidate;
 			*inter_obj->hit_part = 0;
 		}
 	}
}

bool	intersect_cylinder(t_ray ray, t_obj cylinder, t_hit *hit_info, int *hit_part)
{
	t_cyl_inter	inter_obj;

	hit_info->t0 = INFINITY;
 	*hit_part = -1;
	inter_obj.hit_part = hit_part;
 	inter_obj.oc = vec_sub(ray.origin, cylinder.coordinates);
 	inter_obj.dir_dot_axis = dot(ray.destination, cylinder.normalized);
 	inter_obj.ray_perp_dir = vec_sub(ray.destination, vec_mul_num(cylinder.normalized, inter_obj.dir_dot_axis));
 	inter_obj.ray_perp_len = dot(inter_obj.ray_perp_dir, inter_obj.ray_perp_dir);
 	inter_obj.oc_dot_axis = dot(inter_obj.oc, cylinder.normalized);
 	inter_obj.oc_proj = vec_sub(inter_obj.oc, vec_mul_num(cylinder.normalized, inter_obj.oc_dot_axis));
 	calc_discriminant(&inter_obj, cylinder);
 	if (inter_obj.discriminant >= 0.0f)
		check_valid_body_hits(&inter_obj, ray, cylinder, hit_info);
	check_caps_intersection(cylinder, hit_info, ray, hit_part);
	return (*hit_part != -1);
}
