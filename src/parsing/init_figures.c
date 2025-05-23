/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_figures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:44:08 by azinchen          #+#    #+#             */
/*   Updated: 2025/05/18 15:53:20 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

int	init_sphere(t_rt *m, char **args)
{
	t_obj	res;

	res.type = SPHERE;
	if (init_coordinates(&(res.coords), args[1]))
		return (FAILURE);
	rt_atof(args[2], &(res.diameter));
	if (init_colors(&(res.color), args[3]))
		return (FAILURE);
	res.vec_col = rgb_to_vec(res.color);
	res.em_color = (t_vector){0, 0, 0};
	res.normalized = (t_vector){0.0, 1.0, 0.0};
	res.radius = res.diameter / 2;
	m->objects[m->cur_index] = res;
	m->cur_index++;
	m->e_index[E_SPHERE]++;
	return (SUCCESS);
}

int	init_plane(t_rt *m, char **args)
{
	t_obj	res;

	res.type = PLANE;
	if (init_coordinates(&(res.coords), args[1]))
		return (FAILURE);
	if (init_vector(&(res.normalized), args[2]))
		return (FAILURE);
	if (init_colors(&(res.color), args[3]))
		return (FAILURE);
	res.vec_col = rgb_to_vec(res.color);
	res.em_color = (t_vector){0, 0, 0};
	normalize(&res.normalized);
	m->objects[m->cur_index] = res;
	m->cur_index++;
	m->e_index[E_PLANE]++;
	return (SUCCESS);
}

int	init_cylinder(t_rt *m, char **args)
{
	t_obj	res;

	res.type = CYLINDER;
	if (init_coordinates(&(res.coords), args[1]))
		return (FAILURE);
	if (init_vector(&(res.normalized), args[2]))
		return (FAILURE);
	rt_atof(args[3], &(res.diameter));
	rt_atof(args[4], &(res.height));
	if (init_colors(&(res.color), args[5]))
		return (FAILURE);
	res.vec_col = rgb_to_vec(res.color);
	res.em_color = (t_vector){0, 0, 0};
	res.radius = res.diameter / 2;
	normalize(&res.normalized);
	m->objects[m->cur_index] = res;
	m->cur_index++;
	m->e_index[E_CYLINDER]++;
	return (SUCCESS);
}
