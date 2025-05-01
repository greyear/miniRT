/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_rays.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:22:04 by msavelie          #+#    #+#             */
/*   Updated: 2025/05/01 12:07:10 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

static t_vector	calculate_rays(t_vector rayorig, t_vector raydir, t_obj *objects, t_rt *rt)
{
	float	tnear = INFINITY;
	t_obj	*object = NULL;
	t_ray	ray = {rayorig, raydir};
	t_hit	hit_arr[2];

	hit_arr[0] = (t_hit) {INFINITY, INFINITY, -1, -1};
	hit_arr[1] = hit_arr[0];
	object = check_obj_intersection(rt, ray, (t_hit *[2]) {&hit_arr[0], &hit_arr[1]}, &tnear);

	if (!object)
		return ((t_vector){1, 1, 0.5});

	t_vector phit = vec_add(rayorig, vec_mul_num(raydir, tnear));
	t_vector nhit;

	// if (object->type == SPHERE)
	// {
	// 	nhit = vec_sub(phit, object->coordinates);
	// 	normalize(&nhit);
	// }
	// else if (object->type == CYLINDER)
	// {
	// 	if (hit_arr[1].hit_part == 0)
	// 	{
	// 		t_vector hit_to_center = vec_sub(phit, object->coordinates);
	// 		float h = dot(hit_to_center, object->normalized);
	// 		t_vector axis_proj = vec_mul_num(object->normalized, h);
	// 		nhit = vec_sub(hit_to_center, axis_proj);
	// 		normalize(&nhit);
	// 	}
	// 	else if (hit_arr[1].hit_part == 1)
	// 		nhit = vec_mul_num(object->normalized, -1.0f);
	// 	else
	// 		nhit = object->normalized;
	// }
	// else
	// 	nhit = object->normalized;
	normilize_object(object, &nhit, &phit, hit_arr[1]);

	float bias = 1e-4;
	if (dot(raydir, nhit) > 0)
		nhit = revert_vector(nhit);

	t_vector transmission = {1, 1, 1};
	t_vector light_direction = vec_sub(rt->light->coordinates, phit);
	normalize(&light_direction);
	t_vector light_rayorig = {0, 0, 0};
	t_ray	light_ray = {light_rayorig, light_direction};

	for (int j = 0; j < rt->obj_count; ++j) {
		if (&objects[j] == object)
			continue;

		hit_arr[0].t0 = 0;
		hit_arr[0].t1 = 0;
		hit_arr[0].temp_part = -1;
		light_ray.origin = vec_add(phit, vec_mul_num(nhit, bias));

		bool shadow_hit = false;
		if (objects[j].type == SPHERE)
			shadow_hit = intersect_sphere(light_ray, objects[j], &hit_arr[0]) && hit_arr[0].t0 > 0;
		else if (objects[j].type == CYLINDER)
			shadow_hit = intersect_cylinder(light_ray, objects[j], &hit_arr[0]) && hit_arr[0].t0 > 0;
		else if (objects[j].type == PLANE) {
			float plane_side_phit = dot(vec_sub(phit, objects[j].coordinates), objects[j].normalized);
			float plane_side_light = dot(vec_sub(rt->light->coordinates, objects[j].coordinates), objects[j].normalized);
		
			if (plane_side_phit * plane_side_light < 0.0f)
				shadow_hit = intersect_plane(light_ray, objects[j], &hit_arr[0].t0) && hit_arr[0].t0 > 0;
		}
		if (shadow_hit) {
			transmission = (t_vector){0, 0, 0};
			break;
		}
	}

	float light_intensity = fmax(0, dot(nhit, light_direction));
	t_vector light_contribution = vec_mul(
		object->color,
		vec_mul_num(rt->light->emission_color, light_intensity)
	);
	light_contribution = vec_mul(light_contribution, transmission);

	// Ambient + emissive
	t_vector surface_color = light_contribution;
	surface_color = vec_add(surface_color, object->emission_color);
	t_vector ambient_light = (t_vector){0.1, 0.1, 0.1};
	surface_color = vec_add(surface_color, vec_mul(object->color, ambient_light));

	return surface_color;
}

t_vector	*render(t_rt *rt)
{
	t_vector	*pixel = ft_calloc(WIN_WIDTH * WIN_HEIGHT, sizeof(t_vector));
	if (!pixel)
	{
		printf("malloc error\n");
		exit (1);
	}
	float fov = 70;
	float aspect_ratio = WIN_WIDTH / (float) WIN_HEIGHT;
	float angle = tan(M_PI * 0.5 * fov / 180.0);
	unsigned int seed = 123;

	for (int y = 0; y < WIN_HEIGHT; ++y) {
		for (int x = 0; x < WIN_WIDTH; ++x) {
			t_vector pixel_color = {0, 0, 0};
			for (int s = 0; s < PIXEL_SAMPLES; ++s) {
				float u = (x + random_float_fast(&seed)) / (float) WIN_WIDTH;
				float v = (y + random_float_fast(&seed)) / (float) WIN_HEIGHT;

				float xx = (2 * u - 1) * angle * aspect_ratio;
				float yy = (1 - 2 * v) * angle;
				t_vector raydir = { xx, yy, -1 };
				normalize(&raydir);

				t_vector color = calculate_rays(rt->camera->coordinates, raydir, rt->objects, rt);
				pixel_color = vec_add(pixel_color, color);
			}
			pixel_color = vec_mul_num(pixel_color, 1.0f / PIXEL_SAMPLES);
			clamp(&pixel_color);
			pixel[x + WIN_WIDTH * y] = pixel_color; 
		}
	}
	return (pixel);
}
