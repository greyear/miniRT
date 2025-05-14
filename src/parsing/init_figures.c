/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_figures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:44:08 by azinchen          #+#    #+#             */
/*   Updated: 2025/05/13 12:44:09 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

//TODO: alloc outside and fill here
int	init_sphere(t_rt *m, char **args)
{
	t_obj	res;

	res.type = SPHERE;
	if (init_coordinates(&(res.coordinates), args[1]))
		return (FAILURE);
	rt_atof(args[2], &(res.diameter));
	if (init_colors(&(res.color), args[3]))
		return (FAILURE);
	res.vec_col = rgb_to_vec(res.color);
	res.emission_color = (t_vector) {0,0,0};
	res.normalized = (t_vector) { 0.0, 1.0, 0.0};
	res.radius = res.diameter / 2;
	//i = m->e_index[E_SPHERE];
	m->objects[m->cur_index] = res;
	m->cur_index++;
	m->e_index[E_SPHERE]++;
	return (SUCCESS);
}

int	init_plane(t_rt *m, char **args)
{
	t_obj	res;
	//int		i;

	res.type = PLANE;
	if (init_coordinates(&(res.coordinates), args[1]))
		return (FAILURE);
	if (init_vector(&(res.normalized), args[2]))
		return (FAILURE);
	if (init_colors(&(res.color), args[3]))
		return (FAILURE);
	res.vec_col = rgb_to_vec(res.color);
	res.emission_color = (t_vector) {0,0,0};
	//res.normalized = (t_vector) { 0.0, 1.0, 0.0};
	//i = m->e_index[E_PLANE];
	m->objects[m->cur_index] = res;
	m->cur_index++;
	m->e_index[E_PLANE]++;
	return (SUCCESS);
}

int	init_cylinder(t_rt *m, char **args)
{
	t_obj	res;
	//int			i;

	res.type = CYLINDER;
	if (init_coordinates(&(res.coordinates), args[1]))
		return (FAILURE);
	if (init_vector(&(res.normalized), args[2]))
		return (FAILURE);
	rt_atof(args[3], &(res.diameter));
	rt_atof(args[4], &(res.height));
	if (init_colors(&(res.color), args[5]))
		return (FAILURE);
	res.vec_col = rgb_to_vec(res.color);
	res.emission_color = (t_vector) {0,0,0};
	res.radius = res.diameter / 2;
	//makres.normalized = (t_vector) { 0.0, 1.0, 0.0};
	//i = m->e_index[E_CYLINDER];
	m->objects[m->cur_index] = res;
	m->cur_index++;
	m->e_index[E_CYLINDER]++;
	return (SUCCESS);
}
