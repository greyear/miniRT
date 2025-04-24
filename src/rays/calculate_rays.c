/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_rays.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:22:04 by msavelie          #+#    #+#             */
/*   Updated: 2025/04/24 16:29:21 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

static inline void normalize(t_vector *vector_to_norm)
{
	float	normalized = length2(*vector_to_norm);
	if (normalized > 0)
	{
		float invNor = 1 / sqrt(normalized);
		vector_to_norm->x *= invNor;
		vector_to_norm->y *= invNor;
		vector_to_norm->z *= invNor;
	}
}

static t_vector	calculate_rays(t_vector rayorig, t_vector raydir, t_obj *objects, t_miniRT *rt)
{
	float	tnear = INFINITY;
	t_obj	*object = NULL;
	int		hit_part = -1;

	for (int i = 0; i < rt->obj_count; i++) {
		float t0 = INFINITY, t1 = INFINITY;
		int temp_part = -1;
		bool hit = false;

		if (objects[i].type == SPHERE)
			hit = intersect_sphere(rayorig, raydir, objects[i], &t0, &t1);
		else if (objects[i].type == CYLINDER)
			hit = intersect_cylinder(rayorig, raydir, objects[i], &t0, &temp_part);

		if (hit) {
			if (t0 < 0) t0 = t1;
			if (t0 < tnear) {
				tnear = t0;
				object = &objects[i];
				hit_part = temp_part;
			}
		}
	}

	if (!object)
		return ((t_vector){1, 1, 0.5});

	t_vector phit = vec_add(rayorig, vec_mul_num(raydir, tnear));
	t_vector nhit;

	if (object->type == SPHERE)
	{
		nhit = vec_sub(phit, object->coordinates);
		normalize(&nhit);
	}
	else
	{
		if (hit_part == 0)
		{
			t_vector hit_to_center = vec_sub(phit, object->coordinates);
			float h = dot(hit_to_center, object->normalized);
			t_vector axis_proj = vec_mul_num(object->normalized, h);
			nhit = vec_sub(hit_to_center, axis_proj);
			normalize(&nhit);
		}
		else if (hit_part == 1)
		{
			nhit = vec_mul_num(object->normalized, -1.0f);
		}
		else
		{
			nhit = object->normalized;
		}
	}

	float bias = 1e-4;
	if (dot(raydir, nhit) > 0)
		nhit = revert_vector(nhit);

	t_vector transmission = {1, 1, 1};
	t_vector light_direction = vec_sub(rt->light->coordinates, phit);
	normalize(&light_direction);

	for (int j = 0; j < rt->obj_count; ++j) {
		if (&objects[j] == object)
			continue;

		float t0, t1;
		int temp_part = -1;
		t_vector light_rayorig = vec_add(phit, vec_mul_num(nhit, bias));

		bool shadow_hit = false;
		if (objects[j].type == SPHERE)
			shadow_hit = intersect_sphere(light_rayorig, light_direction, objects[j], &t0, &t1) && t0 > 0;
		else if (objects[j].type == CYLINDER)
			shadow_hit = intersect_cylinder(light_rayorig, light_direction, objects[j], &t0, &temp_part) && t0 > 0;

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

t_vector	*render(t_miniRT *rt) {
	rt->objects = ft_calloc(rt->obj_count + 1, sizeof(t_obj));
	if (!rt->objects)
	{
		printf("Malloc error\n");
		exit(1);
	}
	t_vector coordinates = {0, -2, -20}, em_color = {0, 0, 0};
	for (int i = 0; i < rt->obj_count; i++)
	{
		t_obj_type type = i == 0 ? SPHERE : CYLINDER;
		// t_obj_type type = SPHERE;
		rt->objects[i] = init_obj(coordinates, em_color, type);
		coordinates = vec_sub_num(coordinates, 5);
		em_color.x -= 0.1;
	}
	rt->light = ft_calloc(1, sizeof(t_light));
	if (!rt->light)
	{
		printf("Malloc error\n");
		exit(1);
	}
	init_light(rt->light);
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
