/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_for_testing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:46:06 by azinchen          #+#    #+#             */
/*   Updated: 2025/05/18 15:53:59 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/mini_rt.h"

void print_vector(const char *name, t_vector v) {
	printf("%s: (%.2f, %.2f, %.2f)\n", name, v.x, v.y, v.z);
}

void print_color(const char *name, t_col c) {
	printf("%s: (R:%d, G:%d, B:%d)\n", name, c.r, c.g, c.b);
}

void print_figures(t_obj *objects, int obj_count) {
	for (int i = 0; i < obj_count; ++i) {
		if (objects[i].type == SPHERE) {
			printf("-- Sphere #%d --\n", i + 1);
			print_vector("Position", objects[i].coords);
			printf("Diameter: %.2f\n", objects[i].diameter);
			print_color("Color", objects[i].color);
			print_vector("Vec Color", objects[i].vec_col);
		}
		else if (objects[i].type == CYLINDER) {
			printf("-- Cylinder #%d --\n", i + 1);
			print_vector("Position", objects[i].coords);
			print_vector("Normal", objects[i].normalized);
			printf("Diameter: %.2f\n", objects[i].diameter);
			printf("Height: %.2f\n", objects[i].height);
			print_color("Color", objects[i].color);
			print_vector("Vec Color", objects[i].vec_col);
		}
		else if (objects[i].type == PLANE) {
			printf("-- Plane #%d --\n", i + 1);
			print_vector("Position", objects[i].coords);
			print_vector("Normal", objects[i].normalized);
			print_color("Color", objects[i].color);
			print_vector("Vec Color", objects[i].vec_col);
		}
	}
} 

void print_scene_info(t_rt *m)
{
	// Ambient
	printf("=== Ambient Light ===\n");
	printf("Ratio: %.2f\n", m->amb_light.ratio);
	print_color("Color", m->amb_light.color);

	// Camera
	printf("\n=== Camera ===\n");
	print_vector("Position", m->camera.coords);
	print_vector("Direction", m->camera.normalized);
	printf("Field of View: %d\n", m->camera.fov);

	// Light
	printf("\n=== Light Source ===\n");
	print_vector("Position", m->light.coords);
	printf("Intensity: %.2f\n", m->light.ratio);
	print_color("Color", m->light.color);
	print_vector("Vector color", m->light.vec_col);
	printf("\n");
	
	print_figures(m->objects, m->obj_count);

	printf("\nObject total: %d\n", m->obj_count);
}
