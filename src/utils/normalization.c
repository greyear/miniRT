/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:02:43 by msavelie          #+#    #+#             */
/*   Updated: 2025/05/12 15:21:02 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

inline void normalize(t_vector *vector_to_norm)
{
	float	normalized;
	float	invNor;

	normalized = length2(*vector_to_norm);
	if (normalized > 0)
	{
		invNor = 1 / sqrt(normalized);
		vector_to_norm->x *= invNor;
		vector_to_norm->y *= invNor;
		vector_to_norm->z *= invNor;
	}
}

static void	normalize_cylinder(t_obj *object, t_hit cyl_hit, t_vector *nhit, t_vector *phit)
{
	if (cyl_hit.hit_part == 0)
	{
		t_vector hit_to_center = vec_sub(*phit, object->coordinates);
		float h = dot(hit_to_center, object->normalized);
		t_vector axis_proj = vec_mul_num(object->normalized, h);
		*nhit = vec_sub(hit_to_center, axis_proj);
		normalize(nhit);
	}
	else if (cyl_hit.hit_part == 1)
		*nhit = vec_mul_num(object->normalized, -1.0f);
	else
		*nhit = object->normalized;
}

void	normilize_object(t_obj *object, t_vector *nhit, t_vector *phit, t_hit cyl_hit)
{
	if (object->type == SPHERE)
	{
		*nhit = vec_sub(*phit, object->coordinates);
		normalize(nhit);
	}
	else if (object->type == CYLINDER)
		normalize_cylinder(object, cyl_hit, nhit, phit);
	else
		*nhit = object->normalized;
}
