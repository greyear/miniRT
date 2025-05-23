/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:02:43 by msavelie          #+#    #+#             */
/*   Updated: 2025/05/20 17:21:28 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

inline void	normalize(t_vector *vector_to_norm)
{
	float	normalized;
	float	inv_nor;

	normalized = length2(*vector_to_norm);
	if (normalized > 0)
	{
		inv_nor = 1 / sqrt(normalized);
		vector_to_norm->x *= inv_nor;
		vector_to_norm->y *= inv_nor;
		vector_to_norm->z *= inv_nor;
	}
}

t_vector	normalize_return(t_vector vector_to_norm)
{
	float		normalized;
	float		inv_nor;
	t_vector	res;

	res = (t_vector){0, 0, 0};
	normalized = length2(vector_to_norm);
	if (normalized > 0)
	{
		inv_nor = 1 / sqrt(normalized);
		res.x = vector_to_norm.x * inv_nor;
		res.y = vector_to_norm.y * inv_nor;
		res.z = vector_to_norm.z * inv_nor;
	}
	return (res);
}

static void	normalize_cylinder(t_obj *object, t_hit cyl_hit,
	t_vector *nhit, t_vector *phit)
{
	t_vector	hit_to_center;
	t_vector	axis_proj;
	float		h;

	if (cyl_hit.hit_part == 0)
	{
		hit_to_center = vec_sub(*phit, object->coords);
		h = dot(hit_to_center, object->normalized);
		axis_proj = vec_mul_num(object->normalized, h);
		*nhit = vec_sub(hit_to_center, axis_proj);
		normalize(nhit);
	}
	else if (cyl_hit.hit_part == 1)
		*nhit = vec_mul_num(object->normalized, -1.0f);
	else
		*nhit = object->normalized;
}

void	normilize_object(t_obj *object, t_vector *nhit,
	t_vector *phit, t_hit cyl_hit)
{
	if (object->type == SPHERE)
	{
		*nhit = vec_sub(*phit, object->coords);
		normalize(nhit);
	}
	else if (object->type == CYLINDER)
		normalize_cylinder(object, cyl_hit, nhit, phit);
	else
		*nhit = object->normalized;
}
