/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_for_testing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:46:06 by azinchen          #+#    #+#             */
/*   Updated: 2025/05/13 12:46:09 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

void print_vector(const char *name, t_vector v) {
	printf("%s: (%.2f, %.2f, %.2f)\n", name, v.x, v.y, v.z);
}

void print_color(const char *name, t_col c) {
	printf("%s: (R:%d, G:%d, B:%d)\n", name, c.r, c.g, c.b);
}

void print_scene_info(t_miniRT *m)
{
	// Ambient
	printf("=== Ambient Light ===\n");
	printf("Ratio: %.2f\n", m->amb_light.ratio);
	print_color("Color", m->amb_light.color);

	// Camera
	printf("\n=== Camera ===\n");
	print_vector("Position", m->camera.coordinates);
	print_vector("Direction", m->camera.normalized);
	printf("Field of View: %d\n", m->camera.view_field);

	// Light
	printf("\n=== Light Source ===\n");
	print_vector("Position", m->light.coordinates);
	printf("Intensity: %.2f\n", m->light.ratio);
	print_color("Color", m->light.color);

	// Spheres
	printf("\n=== Spheres (%d) ===\n", m->e_count[E_SPHERE]);
	for (int i = 0; i < m->e_count[E_SPHERE]; i++) {
		printf("-- Sphere #%d --\n", i + 1);
		print_vector("Position", m->spheres[i].coordinates);
		printf("Diameter: %.2f\n", m->spheres[i].diameter);
		print_color("Color", m->spheres[i].color);
	}

	// Planes
	printf("\n=== Planes (%d) ===\n", m->e_count[E_PLANE]);
	for (int i = 0; i < m->e_count[E_PLANE]; i++) {
		printf("-- Plane #%d --\n", i + 1);
		print_vector("Position", m->planes[i].coordinates);
		print_vector("Normal", m->planes[i].normalized);
		print_color("Color", m->planes[i].color);
	}

	// Cylinders
	printf("\n=== Cylinders (%d) ===\n", m->e_count[E_CYLINDER]);
	for (int i = 0; i < m->e_count[E_CYLINDER]; i++) {
		printf("-- Cylinder #%d --\n", i + 1);
		print_vector("Position", m->cylinders[i].coordinates);
		print_vector("Normal", m->cylinders[i].normalized);
		printf("Diameter: %.2f\n", m->cylinders[i].diameter);
		printf("Height: %.2f\n", m->cylinders[i].height);
		print_color("Color", m->cylinders[i].color);
	}
}
