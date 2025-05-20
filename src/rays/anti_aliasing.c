/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anti_aliasing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:40:55 by msavelie          #+#    #+#             */
/*   Updated: 2025/05/18 15:54:07 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

/*static t_vector	calculate_raydir(int x, int y, unsigned int *seed, t_rt *rt)
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
	raydir = (t_vector){xx, yy, -1};
	return (raydir);
}*/

//скалярное произведение двух векторов
float	dot_product(t_vector a, t_vector b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vector	cross_product(t_vector a, t_vector b)
{
	t_vector	res;

	res.x = a.y * b.z - a.z * b.y;
	res.y = a.z * b.x - a.x * b.z;
	res.z = a.x * b.y - a.y * b.x;
	return (res);
}

static t_vector	calculate_raydir(int x, int y, unsigned int *seed, t_rt *rt)
{
	float		u;
	float		v;
	float		xx;
	float		yy;
	t_vector	raydir;
	t_vector	local_ray;
	t_vector	forward;
	t_vector	right;
	t_vector	up;
	t_vector	up_guess;

	u = (x + random_float_fast(seed)) / (float) rt->width;
	v = (y + random_float_fast(seed)) / (float) rt->height;
	xx = (2 * u - 1) * rt->camera.angle * rt->camera.aspect_ratio;
	yy = (1 - 2 * v) * rt->camera.angle;
	local_ray = (t_vector){xx, yy, -1};
	forward = normalize_return(rt->camera.normalized);
	up_guess = (t_vector){0, 1, 0};
	if (fabs(dot_product(forward, up_guess)) > 0.99) //they are parallel
		up_guess = (t_vector){1, 0, 0};
	right = normalize_return(cross_product(up_guess, forward));
	up = cross_product(forward, right);
	raydir = vec_add(vec_add(vec_mul_num(right, local_ray.x), vec_mul_num(up, local_ray.y)), vec_mul_num(forward, -local_ray.z));
	return (normalize_return(raydir));
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
		color = calculate_rays(rt->camera.coords, raydir, rt);
		pixel_color = vec_add(pixel_color, color);
		s++;
	}
	return (pixel_color);
}
