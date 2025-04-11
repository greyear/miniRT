/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_rays.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:22:04 by msavelie          #+#    #+#             */
/*   Updated: 2025/04/11 17:48:32 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

// move to a structs.h later 
typedef enum s_calc
{
	ADD,
	SUBTRACT,
	MULTIPLY,
	DIVIDE
}	t_calc;

// here will be an obj from parsing
static t_obj	init_obj(void)
{
	t_obj	def_obj;
	t_color	color;

	color.cur_color = 0xff0000;
	def_obj.type = SPHERE;
	def_obj.color = color;
	def_obj.coordinates = (t_vector){ 10.0, 20.0, 10.0 };
	def_obj.normalized = (t_vector){ 0.0, 1.0, 0.0 };
	def_obj.width = 0;
	def_obj.diameter = 10.5;
	def_obj.height = 0;
	return (def_obj);
}

t_vector	calculate_with_vector(t_vector vec1, t_vector vec2, t_calc operation)
{
	t_vector	result;
	if (operation == ADD)
		result = (t_vector) {vec1.x + vec2.x, vec1.y + vec2.y, vec1.z + vec2.z};
	else if (operation == SUBTRACT)
		result = (t_vector) {vec1.x - vec2.x, vec1.y - vec2.y, vec1.z - vec2.z};
	else if (operation == MULTIPLY)
		result = (t_vector) {vec1.x * vec2.x, vec1.y * vec2.y, vec1.z * vec2.z};
	else
		result = (t_vector) {vec1.x / vec2.x, vec1.y / vec2.y, vec1.z / vec2.z};
	return (result);

}

static bool	intersect(t_vector raydir, t_obj sphere, double *t0, double *t1) 
{
	double		radius2 = pow(sphere.diameter / 2, 2);
	t_vector	center = (t_vector) {10, 0, 0};
	t_vector	ray_orig = (t_vector) {0, 0, 0};
	t_vector	ray_length = calculate_with_vector(center, ray_orig, SUBTRACT);
	double		tca = ray_length.x * raydir.x + ray_length.y * raydir.y + ray_length.z * raydir.z;
	if (tca < 0)
		return (false);
	double		d2 = pow(ray_length.x, 2) + pow(ray_length.y, 2) + pow(ray_length.z, 2) - tca * tca;
	if (d2 > radius2)
		return false;
	float thc = sqrt(radius2 - d2);
	*t0 = tca - thc;
	*t1 = tca + thc;
	return (true);
}

static double	length2(t_vector vec)
{
	return (pow(vec.x, 2) + pow(vec.y, 2) + pow(vec.z, 2));
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

t_vector	calculate_rays(t_vector raydir)
{
	t_obj	spheres[2];

	spheres[0] = init_obj();
	spheres[1] = init_obj();
	double	tnear = INFINITY;
	for (int i = 0; i < 2; i++) {
		double t0 = INFINITY, t1 = INFINITY;
		if (intersect(raydir, spheres[i], &t0, &t1))
		{
			if (t0 < 0)
				t0 = t1;
			if (t0 < tnear)
			{
				tnear = t0;
			}
		}
	}
	return ((t_vector){255, 0, 0});
}

void	render(void) {
	double invWidth = 1 / (double) WIN_WIDTH, invHeight = 1 / (double) WIN_HEIGHT;
	t_vector	*pixel = ft_calloc(WIN_WIDTH * WIN_HEIGHT, sizeof(t_vector)); 
	double fov = 70;
	double aspect_ratio = WIN_WIDTH / (double) WIN_HEIGHT;
	double angle = tan(M_PI * 0.5 * fov / 180.0);

	for (int y = 0; y < WIN_HEIGHT; ++y) {
		for (int x = 0; x < WIN_WIDTH; ++x, ++pixel) {
			double xx = (2 * ((x + 0.5) * invWidth) - 1) * angle * aspect_ratio;
			double yy = (1 - 2 * ((y + 0.5) * invHeight) - 1) * angle;
			t_vector raydir = (t_vector) { xx, yy, -1 };
			normalize(&raydir);
			*pixel = calculate_rays(raydir);
		}
	}
}
