/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:35:04 by msavelie          #+#    #+#             */
/*   Updated: 2025/05/02 15:40:11 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

// here will be an obj from parsing
t_obj	init_obj(t_vector coordinates, t_vector em_color, t_obj_type type)
{
	t_obj		def_obj;

	def_obj.type = type;
	def_obj.color = (t_vector) {1, 0, 1};
	def_obj.emission_color = em_color;
	def_obj.coordinates = coordinates;
	def_obj.normalized = (t_vector) { 0.0, 1.0, 0.0};
	//normalize(&def_obj.normalized);
	def_obj.diameter = 10.5;
	def_obj.radius = def_obj.diameter / 2;
	def_obj.height = 10;
	return (def_obj);
}

t_obj	*init_objects(t_rt *rt)
{
	t_obj		*objects;
	t_vector	em_color;

	em_color = (t_vector) {0, 0, 0};
	objects = ft_calloc(rt->obj_count, sizeof(t_obj));
	if (!objects)
		clean_exit(rt);
	objects[0] = init_obj((t_vector) {0, -2, -20}, em_color, SPHERE);
	objects[1] = init_obj((t_vector) {-5, -7, -25}, em_color, CYLINDER);
	objects[2] = init_obj((t_vector) {0, -7, 0}, em_color, PLANE);
	return (objects);
}

t_light	*init_light(t_rt *rt)
{
	t_light	*light;

	light = ft_calloc(1, sizeof(t_light));
	if (!light)
		clean_exit(rt);
	light->coordinates = (t_vector) {10, 0, 5};
	light->color = (t_vector) {1, 1, 1};
	light->emission_color = (t_vector) {1, 1, 1},
	light->diameter = 5.f;
	light->ratio = 1.f;
	return (light);
}

t_camera	*init_camera(void)
{
	t_camera	*camera;

	camera = ft_calloc(1, sizeof(t_camera));
	if (!camera)
		clean_exit(NULL);
	camera->coordinates = (t_vector) {0, 0, 0};
	camera->fov = 70;
	camera->aspect_ratio = WIN_WIDTH / (float) WIN_HEIGHT;
	camera->angle = tan(M_PI * 0.5 * camera->fov / 180.0);
	return (camera);
}
