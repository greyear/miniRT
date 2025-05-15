/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_rays.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:22:04 by msavelie          #+#    #+#             */
/*   Updated: 2025/05/05 14:52:16 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

static t_light_calc	calculate_lights(t_rt *rt, t_obj *object, t_hit *hit_arr)
{
	t_light_calc	lights;

	lights.transmission = (t_vector){1, 1, 1};
	lights.light_ray.destination = vec_sub(rt->light.coordinates, hit_arr[0].phit);
	normalize(&lights.light_ray.destination);
	lights.light_ray.origin = (t_vector){0, 0, 0};
	t_ray	light_ray = {lights.light_ray.origin, lights.light_ray.destination};
	lights.transmission = calculate_shadows(rt, object, &hit_arr[0], light_ray);
	lights.light_intensity = fmax(0, dot(hit_arr[0].nhit, lights.light_ray.destination));
	t_vector light_contribution = vec_mul(object->vec_col,
		vec_mul_num(rt->light.emission_color, lights.light_intensity));
	light_contribution = vec_mul(light_contribution, lights.transmission);
	lights.surface_color = light_contribution;
	lights.surface_color = vec_add(lights.surface_color, object->emission_color);
	lights.surface_color = vec_add(lights.surface_color, vec_mul(object->vec_col, rt->amb_light.vec_col));
	return (lights);	
}

t_vector	calculate_rays(t_vector rayorig, t_vector raydir, t_rt *rt)
{
	float			tnear;
	t_obj			*object;
	t_ray			ray = {rayorig, raydir};
	t_hit			hit_arr[2];
	t_light_calc	lights;

	tnear = INFINITY;
	object = NULL;
	hit_arr[0] = (t_hit) {INFINITY, INFINITY, -1, -1, {0,0,0}, {0,0,0}};
	hit_arr[1] = hit_arr[0];
	object = check_obj_intersection(rt, ray, (t_hit *[2]) {&hit_arr[0], &hit_arr[1]}, &tnear);
	if (!object)
		return ((t_vector){1, 1, 0.5}); //should there be hardcode?
	hit_arr[0].phit = vec_add(rayorig, vec_mul_num(raydir, tnear));
	normilize_object(object, &hit_arr[0].nhit, &hit_arr[0].phit, hit_arr[1]);
	if (dot(raydir, hit_arr[0].nhit) > 0)
		hit_arr[0].nhit = revert_vector(hit_arr[0].nhit);
	lights = calculate_lights(rt, object, hit_arr);
	return (lights.surface_color);
}

void	render(t_rt *rt)
{
	t_vector		pixel_color;
	int				x;
	int				y;

	x = 0;
	y = 0;
	while (y < rt->height)
	{
		x = 0;
		while (x < rt->width)
		{
			pixel_color = smooth_pixel(x, y, rt);
			pixel_color = vec_mul_num(pixel_color, 1.0f / PIXEL_SAMPLES);
			clamp(&pixel_color);
			rt->image[x + rt->width * y] = pixel_color;
			x++;
		}
		y++;
	}
}
