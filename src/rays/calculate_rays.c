/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_rays.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:22:04 by msavelie          #+#    #+#             */
/*   Updated: 2025/04/17 15:34:48 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

// here will be an obj from parsing
static t_obj	init_obj(t_vector coordinates, t_vector em_color)
{
	t_obj		def_obj;

	def_obj.type = SPHERE;
	def_obj.color = (t_vector) {1, 0, 1};
	def_obj.emission_color = em_color;
	def_obj.coordinates = coordinates;
	def_obj.normalized = (t_vector){ 0.0, 0.0, 0.0 };
	def_obj.width = 0;
	def_obj.diameter = 10.5;
	def_obj.height = 0;
	return (def_obj);
}

static void	init_light(t_light *light)
{
	light->coordinates = (t_vector){10, 0, 5};
	light->color = (t_vector){1, 1, 1};
	light->emission_color = (t_vector) {1, 1, 1},
	light->diameter = 5.f;
	light->ratio = 1.f;
}

static bool	intersect(t_vector rayorig, t_vector raydir, t_obj sphere, float *t0, float *t1) 
{
	float		radius2 = pow(sphere.diameter / 2, 2);
	t_vector	center = sphere.coordinates;
	t_vector	ray_length = calculate_with_vector(center, rayorig, SUBTRACT);
	float		tca = ray_length.x * raydir.x + ray_length.y * raydir.y + ray_length.z * raydir.z;
	// if (tca < 0)
	// 	return (false);
	float		d2 = pow(ray_length.x, 2) + pow(ray_length.y, 2) + pow(ray_length.z, 2) - tca * tca;
	if (d2 > radius2)
		return false;
	float thc = sqrt(radius2 - d2);
	*t0 = tca - thc;
	*t1 = tca + thc;
	return (true);
}

static void normalize(t_vector *vector_to_norm)
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

static t_vector	calculate_rays(t_vector rayorig, t_vector raydir, t_obj *spheres, t_miniRT *obj)
{
	float	tnear = INFINITY;
	t_obj	*sphere = NULL;

	for (int i = 0; i < obj->obj_count; i++) {
		float t0 = INFINITY, t1 = INFINITY;
		if (intersect(rayorig, raydir, spheres[i], &t0, &t1))
		{
			if (t0 < 0)
				t0 = t1;
			if (t0 < tnear)
			{
				tnear = t0;
				sphere = &spheres[i];
			}
		}
	}

	if (!sphere)
		return ((t_vector) {1, 1, 0.5});

	t_vector	surface_color = (t_vector) {0, 0, 0};
	t_vector	phit = calculate_with_vector(calculate_with_vector(rayorig, raydir, ADD), (t_vector) {tnear, tnear, tnear}, MULTIPLY);
	t_vector	nhit = calculate_with_vector(phit, sphere->coordinates, SUBTRACT);
	normalize(&nhit);

	float	bias = 1e-4;
	if (dot(raydir, nhit) > 0)
		nhit = revert_vector(nhit);

	// Light calc
	t_vector transmission = (t_vector) {1, 1, 1};
	t_vector light_direction = calculate_with_vector(obj->light->coordinates, phit, SUBTRACT);
	normalize(&light_direction);
	for (int j = 0; j < obj->obj_count; ++j) {
		if (&spheres[j] == sphere)
			continue;
		float t0, t1;
		t_vector light_rayorig = calculate_with_vector(
			phit,
			calculate_with_number(nhit, bias, MULTIPLY),
			ADD
		);
		if (&spheres[j] != sphere && intersect(light_rayorig, light_direction, spheres[j], &t0, &t1) && t0 > 0)
		{
			transmission = (t_vector) {0,0,0};
			break ;
		}
	}
	float light_intensity = max(0, dot(nhit, light_direction));
	t_vector light_contribution = calculate_with_vector(
		sphere->color,
		calculate_with_number(obj->light->emission_color, light_intensity, MULTIPLY),
		MULTIPLY);
	light_contribution = calculate_with_vector(light_contribution, transmission, MULTIPLY);
	surface_color = calculate_with_vector(surface_color, light_contribution, ADD);
	surface_color = calculate_with_vector(surface_color, sphere->emission_color, ADD);
	t_vector ambient_light = (t_vector){0.1, 0.1, 0.1};
	t_vector ambient = calculate_with_vector(sphere->color, ambient_light, MULTIPLY);
	surface_color = calculate_with_vector(surface_color, ambient, ADD);
	return (surface_color);
}

t_vector	*render(t_miniRT *obj) {
	obj->objects = ft_calloc(obj->obj_count + 1, sizeof(t_obj));
	if (!obj->objects)
	{
		printf("Malloc error\n");
		exit(1);
	}
	t_vector coordinates = {0, -2, -20}, em_color = {0, 0, 0};
	for (int i = 0; i < obj->obj_count; i++)
	{
		obj->objects[i] = init_obj(coordinates, em_color);
		coordinates = calculate_with_number(coordinates, 5, SUBTRACT);
		em_color.x -= 0.1;
	}
	obj->light = ft_calloc(1, sizeof(t_light));
	if (!obj->light)
	{
		printf("Malloc error\n");
		exit(1);
	}
	init_light(obj->light);
	t_vector	*pixel = ft_calloc(WIN_WIDTH * WIN_HEIGHT, sizeof(t_vector));
	if (!pixel)
	{
		printf("malloc error\n");
		exit (1);
	}
	float fov = 70;
	float aspect_ratio = WIN_WIDTH / (float) WIN_HEIGHT;
	float angle = tan(M_PI * 0.5 * fov / 180.0);

	for (int y = 0; y < WIN_HEIGHT; ++y) {
		for (int x = 0; x < WIN_WIDTH; ++x) {
			t_vector pixel_color = {0, 0, 0};
			for (int s = 0; s < PIXEL_SAMPLES; ++s) {
				float u = (x + random_float()) / (float) WIN_WIDTH;
				float v = (y + random_float()) / (float) WIN_HEIGHT;

				float xx = (2 * u - 1) * angle * aspect_ratio;
				float yy = (1 - 2 * v) * angle;
				t_vector raydir = (t_vector) { xx, yy, -1 };
				normalize(&raydir);

				t_vector color = calculate_rays(obj->camera->coordinates, raydir, obj->objects, obj);
				pixel_color = calculate_with_vector(pixel_color, color, ADD);

			}
			pixel_color = calculate_with_number(pixel_color, 1.0f / PIXEL_SAMPLES, MULTIPLY);
			clamp(&pixel_color);
			pixel[x + WIN_WIDTH * y] = pixel_color; 
		}
	}
	return (pixel);
}
