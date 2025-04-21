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
	def_obj.color = (t_vector) {0, 0, -3};
	def_obj.emission_color = em_color;
	def_obj.coordinates = coordinates;
	def_obj.normalized = (t_vector){ 0.0, 0.0, 0.0 };
	def_obj.width = 0;
	def_obj.diameter = 10.5;
	def_obj.height = 0;
	def_obj.transparency = 0;
	def_obj.reflection = 0;
	return (def_obj);
}

t_obj	init_light(void)
{
	t_obj	light = {
		.coordinates = (t_vector){-10, 10, -10},
		.type = LIGHT,
		.color = (t_vector) {1, 1, 1},
		.emission_color = (t_vector) {1, 1, 1},
		.diameter = 10,
		.transparency = 0,
		.reflection = 0,
		.width = 0,
		.height = 0
	};

	return (light);
}

static bool	intersect(t_vector rayorig, t_vector raydir, t_obj sphere, double *t0, double *t1) 
{
	double		radius2 = pow(sphere.diameter / 2, 2);
	t_vector	center = sphere.coordinates;
	t_vector	ray_length = calculate_with_vector(center, rayorig, SUBTRACT);
	double		tca = ray_length.x * raydir.x + ray_length.y * raydir.y + ray_length.z * raydir.z;
	// if (tca < 0)
	// 	return (false);
	double		d2 = pow(ray_length.x, 2) + pow(ray_length.y, 2) + pow(ray_length.z, 2) - tca * tca;
	if (d2 > radius2)
		return false;
	double thc = sqrt(radius2 - d2);
	*t0 = tca - thc;
	*t1 = tca + thc;
	return (true);
}

static void normalize(t_vector *vector_to_norm)
{
	double	normalized = length2(*vector_to_norm);
	if (normalized > 0)
	{
		double invNor = 1 / sqrt(normalized);
		vector_to_norm->x *= invNor;
		vector_to_norm->y *= invNor;
		vector_to_norm->z *= invNor;
	}
}

t_vector	calculate_rays(t_vector rayorig, t_vector raydir, t_obj *spheres, int depth, t_miniRT *obj)
{
	double	tnear = INFINITY;
	t_obj	*sphere = NULL;

	for (int i = 0; i < obj->obj_count; i++) {
		double t0 = INFINITY, t1 = INFINITY;
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

	double	bias = 1e-4;
	bool	inside = false;
	if (dot(raydir, nhit) > 0)
	{
		nhit = revert_vector(nhit);
		inside = true;
	}
	if ((sphere->transparency > 0 || sphere->reflection > 0) && depth < MAX_DEPTH)
	{
		double facingratio = dot(revert_vector(raydir), nhit);
		double fresneleffect = lerp(pow(1 - facingratio, 3), 1, 0.1);

		t_vector refldir = 
		calculate_with_vector(raydir,
			calculate_with_number(nhit, dot(raydir, nhit) * 2, MULTIPLY),
			SUBTRACT);
		normalize(&refldir);

		t_vector refl_rayorigin = calculate_with_vector(phit,
			calculate_with_number(nhit, bias, MULTIPLY),
			ADD);
		t_vector reflection = calculate_rays(refl_rayorigin, refldir, spheres, depth + 1, obj);
		t_vector refraction = (t_vector) {0, 0, 0};
		if (sphere->transparency) {
			double ior = 1.1;
			double eta;
			if (inside)
				eta = ior;
			else
				eta = 1 / ior;
			double cosi = dot(revert_vector(nhit), raydir);
			double k = 1 - eta * eta * (1 - cosi * cosi);
			t_vector refrdir = calculate_with_vector(
				calculate_with_number(raydir, eta, MULTIPLY),
				calculate_with_number(nhit, eta * cosi - sqrt(k), MULTIPLY),
				SUBTRACT);
			normalize(&refrdir);

			t_vector refr_rayorigin = calculate_with_vector(phit,
			calculate_with_number(nhit, bias, MULTIPLY),
			ADD);
			refraction = calculate_rays(refr_rayorigin, refrdir, spheres, depth + 1, obj);
		}
		surface_color = calculate_with_vector(
			calculate_with_vector(
				calculate_with_number(reflection, fresneleffect, MULTIPLY),
				calculate_with_number(refraction, (1 - fresneleffect) * sphere->transparency, MULTIPLY),
				ADD
			), 
			sphere->color, MULTIPLY);
	}
	else
	{
		for (int i = 0; i < obj->obj_count; ++i) {
			if (spheres[i].emission_color.x > 0)
			{
				t_vector transmission = (t_vector) {1, 1, 1};
				t_vector light_direction = calculate_with_vector(spheres[i].coordinates, phit, SUBTRACT);
				normalize(&light_direction);
				for (int j = 0; j < obj->obj_count; ++j) {
					if (i != j)
					{
						double t0, t1;
						t_vector light_rayorig = calculate_with_vector(
							phit,
							calculate_with_number(nhit, bias, MULTIPLY),
							ADD
						);
						if (i != j && spheres[j].emission_color.x <= 0 && spheres[j].type == SPHERE
							&& intersect(light_rayorig, light_direction, spheres[j], &t0, &t1))
						{
							transmission = (t_vector) {0, 0, 0};
							break ;
						}
					}
				}
				double light_intensity = max(0, dot(nhit, light_direction));
				// if (light_intensity > 0)
				// 	printf("light_intesity: %f\n", light_intensity);
				t_vector light_contribution = calculate_with_vector(
					sphere->color,
					calculate_with_number(spheres[i].emission_color, light_intensity, MULTIPLY),
					MULTIPLY);
				light_contribution = calculate_with_vector(light_contribution, transmission, MULTIPLY);
				surface_color = calculate_with_vector(surface_color, light_contribution, ADD);
			}
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
	t_vector coordinates = {0, -2, -20}, em_color = {0.6, 0, 1};
	for (int i = 0; i < obj->obj_count; i++)
	{
		obj->objects[i] = init_obj(coordinates, em_color);
		coordinates = calculate_with_number(coordinates, 5, SUBTRACT);
		em_color.x -= 0.1;
	}
	obj->objects[obj->obj_count] = init_light();
	double invWidth = 1 / (double) WIN_WIDTH, invHeight = 1 / (double) WIN_HEIGHT;
	t_vector	*pixel = ft_calloc(WIN_WIDTH * WIN_HEIGHT, sizeof(t_vector));
	if (!pixel)
	{
		printf("malloc error\n");
		exit (1);
	}
	double fov = 70;
	double aspect_ratio = WIN_WIDTH / (double) WIN_HEIGHT;
	double angle = tan(M_PI * 0.5 * fov / 180.0);

	for (int y = 0; y < WIN_HEIGHT; ++y) {
		for (int x = 0; x < WIN_WIDTH; ++x) {
			double xx = (2 * ((x + 0.5) * invWidth) - 1) * angle * aspect_ratio;
			double yy = (1 - 2 * ((y + 0.5) * invHeight)) * angle;
			t_vector raydir = (t_vector) { xx, yy, -1 };
			normalize(&raydir);
			pixel[x + WIN_WIDTH * y] = calculate_rays(obj->camera->coordinates, raydir, obj->objects, 0, obj);
			clamp(&pixel[x + WIN_WIDTH * y]);
		}
	}
	return (pixel);
}
