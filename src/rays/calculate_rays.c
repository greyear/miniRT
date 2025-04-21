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

t_obj	init_light(void)
{
	t_obj	light = {
		.coordinates = (t_vector){0, 0, 10},
		.type = LIGHT,
		.color = (t_vector) {1, 1, 1},
		.emission_color = (t_vector) {1, 1, 1},
		.diameter = 10,
		.width = 0,
		.height = 0
	};

	return (light);
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

t_vector	calculate_rays(t_vector rayorig, t_vector raydir, t_obj *spheres, t_miniRT *obj)
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
	for (int i = 0; i < obj->obj_count; ++i) {
		if (spheres[i].type == LIGHT)
		{
			t_vector transmission = (t_vector) {1, 1, 1};
			t_vector light_direction = calculate_with_vector(spheres[i].coordinates, phit, SUBTRACT);
			normalize(&light_direction);
			for (int j = 0; j < obj->obj_count; ++j) {
				if (i != j)
				{
					float t0, t1;
					t_vector light_rayorig = calculate_with_vector(
						phit,
						calculate_with_number(nhit, bias, MULTIPLY),
						ADD
					);
					if (spheres[j].type != LIGHT
						&& intersect(light_rayorig, light_direction, spheres[j], &t0, &t1))
					{
						transmission = (t_vector) {0.2, 0, 0};
						break ;
					}
				}
			}
			float light_intensity = max(0, dot(nhit, light_direction));
			t_vector light_contribution = calculate_with_vector(
				sphere->color,
				calculate_with_number(spheres[i].emission_color, light_intensity, MULTIPLY),
				MULTIPLY);
			light_contribution = calculate_with_vector(light_contribution, transmission, MULTIPLY);
			surface_color = calculate_with_vector(surface_color, light_contribution, ADD);
		}
	}
	return (calculate_with_vector(surface_color, sphere->emission_color, ADD));
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
	obj->objects[obj->obj_count] = init_light();
	obj->obj_count++;
	//obj->objects[obj->obj_count] = NULL;
	float invWidth = 1 / (float) WIN_WIDTH, invHeight = 1 / (float) WIN_HEIGHT;
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
			float xx = (2 * ((x + 0.5) * invWidth) - 1) * angle * aspect_ratio;
			float yy = (1 - 2 * ((y + 0.5) * invHeight)) * angle;
			t_vector raydir = (t_vector) { xx, yy, -1 };
			normalize(&raydir);
			pixel[x + WIN_WIDTH * y] = calculate_rays(obj->camera->coordinates, raydir, obj->objects, obj);
			clamp(&pixel[x + WIN_WIDTH * y]);
		}
	}
	return (pixel);
}
