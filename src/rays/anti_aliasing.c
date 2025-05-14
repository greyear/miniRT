/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anti_aliasing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:40:55 by msavelie          #+#    #+#             */
/*   Updated: 2025/05/12 15:20:40 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

static t_vector	calculate_raydir(int x, int y, unsigned int *seed, t_rt *rt)
{
	float		u;
	float		v;
	float		xx;
	float		yy;
	t_vector	raydir;

	u = (x + random_float_fast(seed)) / (float) rt->width;
	v = (y + random_float_fast(seed)) / (float) rt->height;
	xx = (2 * u - 1) * rt->camera.angle * rt->camera.aspect_ratio;
	yy = (1 - 2 * v) * rt->camera.angle;
	raydir = (t_vector) { xx, yy, -1 };
	return (raydir);
}

t_vector	smooth_pixel(int x, int y, t_rt *rt)
{
	int				s;
	unsigned int	seed;
	t_vector		pixel_color;
	t_vector		raydir;
	t_vector		color;

	seed = 123;
	pixel_color = (t_vector){0, 0, 0};
	s = 0;
	while (s < PIXEL_SAMPLES)
	{
		raydir = calculate_raydir(x, y, &seed, rt);
		normalize(&raydir);
		color = calculate_rays(rt->camera.coordinates, raydir, rt);
		pixel_color = vec_add(pixel_color, color);
		s++;
	}
	return (pixel_color);
}
