/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_rays.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:22:04 by msavelie          #+#    #+#             */
/*   Updated: 2025/05/02 15:36:26 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

static t_light_calc	calculate_lights(t_rt *rt, t_obj *object, t_hit *hit_arr)
{
	t_light_calc	lights;

	lights.transmission = (t_vector){1, 1, 1};
	lights.light_ray.destination = vec_sub(rt->light->coordinates, hit_arr[0].phit);
	normalize(&lights.light_ray.destination);
	lights.light_ray.origin = (t_vector){0, 0, 0};
	t_ray	light_ray = {lights.light_ray.origin, lights.light_ray.destination};
	lights.transmission = calculate_shadows(rt, object, &hit_arr[0], light_ray);
	lights.light_intensity = fmax(0, dot(hit_arr[0].nhit, lights.light_ray.destination));
	t_vector light_contribution = vec_mul(object->color,
		vec_mul_num(rt->light->emission_color, lights.light_intensity));
	light_contribution = vec_mul(light_contribution, lights.transmission);
	lights.surface_color = light_contribution;
	lights.surface_color = vec_add(lights.surface_color, object->emission_color);
	lights.surface_color = vec_add(lights.surface_color, vec_mul(object->color, rt->ambient_light));
	return (lights);	
}

static t_vector	calculate_rays(t_vector rayorig, t_vector raydir, t_rt *rt)
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
		return ((t_vector){1, 1, 0.5});
	hit_arr[0].phit = vec_add(rayorig, vec_mul_num(raydir, tnear));
	normilize_object(object, &hit_arr[0].nhit, &hit_arr[0].phit, hit_arr[1]);
	if (dot(raydir, hit_arr[0].nhit) > 0)
		hit_arr[0].nhit = revert_vector(hit_arr[0].nhit);
	lights = calculate_lights(rt, object, hit_arr);
	return (lights.surface_color);
}

t_vector	*render(t_rt *rt)
{
	float			angle;
	t_vector		*pixel;
	unsigned int	seed;

	seed = 123;
	angle = tan(M_PI * 0.5 * rt->camera->fov / 180.0);
	pixel = ft_calloc(WIN_WIDTH * WIN_HEIGHT, sizeof(t_vector));
	if (!pixel)
		clean_exit(rt);
	
	for (int y = 0; y < WIN_HEIGHT; ++y) {
		for (int x = 0; x < WIN_WIDTH; ++x) {
			t_vector pixel_color = {0, 0, 0};
			for (int s = 0; s < PIXEL_SAMPLES; ++s) {
				float u = (x + random_float_fast(&seed)) / (float) WIN_WIDTH;
				float v = (y + random_float_fast(&seed)) / (float) WIN_HEIGHT;

				float xx = (2 * u - 1) * angle * rt->camera->aspect_ratio;
				float yy = (1 - 2 * v) * angle;
				t_vector raydir = { xx, yy, -1 };
				normalize(&raydir);

				t_vector color = calculate_rays(rt->camera->coordinates, raydir, rt);
				pixel_color = vec_add(pixel_color, color);
			}
			pixel_color = vec_mul_num(pixel_color, 1.0f / PIXEL_SAMPLES);
			clamp(&pixel_color);
			pixel[x + WIN_WIDTH * y] = pixel_color; 
		}
	}
	return (pixel);
}
