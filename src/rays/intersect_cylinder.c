/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:20:41 by msavelie          #+#    #+#             */
/*   Updated: 2025/05/18 16:10:28 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

static inline void	set_ray_candidate(t_cyl_inter *inter_obj, int i)
{
	if (i == 0)
		inter_obj->t_candidate = inter_obj->t0;
	else
		inter_obj->t_candidate = inter_obj->t1;
}

static void	check_valid_body_hits(t_cyl_inter *inter_obj, t_ray ray,
	t_obj cylinder, t_hit *hit_info)
{
	int		i;
	float	height;

	i = -1;
	while (i < 2)
	{
		++i;
		set_ray_candidate(inter_obj, i);
		if (inter_obj->t_candidate < 0.0f)
			continue ;
		inter_obj->intersection = vec_add(ray.orig,
				vec_mul_num(ray.dir, inter_obj->t_candidate));
		inter_obj->to_point = vec_sub(inter_obj->intersection, cylinder.coords);
		height = dot(inter_obj->to_point, cylinder.normalized);
		if (height >= 0.0f && height <= cylinder.height
			&& inter_obj->t_candidate < hit_info->t0)
		{
			hit_info->t0 = inter_obj->t_candidate;
			*inter_obj->hit_part = 0;
		}
	}
}

bool	intersect_cylinder(t_ray ray, t_obj cylinder,
	t_hit *hit_info, int *hit_part)
{
	t_cyl_inter	inter_obj;

	hit_info->t0 = INFINITY;
	*hit_part = -1;
	inter_obj.hit_part = hit_part;
	inter_obj.oc = vec_sub(ray.orig, cylinder.coords);
	inter_obj.dir_dot_axis = dot(ray.dir, cylinder.normalized);
	inter_obj.ray_perp_dir = vec_sub(ray.dir,
			vec_mul_num(cylinder.normalized, inter_obj.dir_dot_axis));
	inter_obj.ray_perp_len = dot(inter_obj.ray_perp_dir,
			inter_obj.ray_perp_dir);
	inter_obj.oc_dot_axis = dot(inter_obj.oc, cylinder.normalized);
	inter_obj.oc_proj = vec_sub(inter_obj.oc,
			vec_mul_num(cylinder.normalized, inter_obj.oc_dot_axis));
	calc_discriminant(&inter_obj, cylinder);
	if (inter_obj.discriminant >= 0.0f)
		check_valid_body_hits(&inter_obj, ray, cylinder, hit_info);
	check_caps_intersection(cylinder, hit_info, ray, hit_part);
	return (*hit_part != -1);
}
