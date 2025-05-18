/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:19:35 by msavelie          #+#    #+#             */
/*   Updated: 2025/05/18 16:52:44 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

inline float	random_float_fast(unsigned int *seed)
{
	*seed ^= *seed << 13;
	*seed ^= *seed >> 17;
	*seed ^= *seed << 5;
	return ((*seed & 0xFFFFFF) / (float)0xFFFFFF);
}

void	compute_quadratic_roots(t_cyl_inter *inter_obj, float b)
{
	float	sqrt_disc;

	sqrt_disc = sqrtf(inter_obj->discriminant);
	inter_obj->t0 = (-b - sqrt_disc) / (2 * inter_obj->ray_perp_len);
	inter_obj->t1 = (-b + sqrt_disc) / (2 * inter_obj->ray_perp_len);
}

void	calc_discriminant(t_cyl_inter *inter_obj, t_obj cylinder)
{
	float	b;
	float	c;

	b = 2.0f * dot(inter_obj->ray_perp_dir, inter_obj->oc_proj);
	c = dot(inter_obj->oc_proj, inter_obj->oc_proj)
		- cylinder.radius * cylinder.radius;
	inter_obj->discriminant = b * b - 4 * inter_obj->ray_perp_len * c;
	if (inter_obj->discriminant >= 0.0f)
		compute_quadratic_roots(inter_obj, b);
}
