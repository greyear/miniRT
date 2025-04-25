/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:35:04 by msavelie          #+#    #+#             */
/*   Updated: 2025/04/24 16:32:23 by msavelie         ###   ########.fr       */
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
	def_obj.normalized = (t_vector){ 0.0, 1.0, 0.0};
	//normalize(&def_obj.normalized);
	def_obj.diameter = 10.5;
	def_obj.radius = def_obj.diameter / 2;
	def_obj.height = 10;
	return (def_obj);
}

void	init_light(t_light *light)
{
	light->coordinates = (t_vector){10, 0, 5};
	light->color = (t_vector){1, 1, 1};
	light->emission_color = (t_vector) {1, 1, 1},
	light->diameter = 5.f;
	light->ratio = 1.f;
}
