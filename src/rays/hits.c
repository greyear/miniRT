/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hits.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 10:34:04 by msavelie          #+#    #+#             */
/*   Updated: 2025/05/01 14:22:41 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

bool	check_intersection(t_ray ray, t_obj object, t_hit *hit_info)
{
	bool	hit;

	hit = false;
	if (object.type == SPHERE)
		hit = intersect_sphere(ray, object, hit_info);
	else if (object.type == CYLINDER)
		hit = intersect_cylinder(ray, object, hit_info, &hit_info->hit_part);
	else if (object.type == PLANE)
		hit = intersect_plane(ray, object, &hit_info->t0);
	return (hit);
}
