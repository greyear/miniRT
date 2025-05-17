/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_non_figures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:44:28 by azinchen          #+#    #+#             */
/*   Updated: 2025/05/17 15:47:12 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

int	init_ambient(t_rt *m, char **args)
{
	t_ambient	res;

	rt_atof(args[1], &(res.ratio));
	if (init_colors(&(res.color), args[2]))
		return (FAILURE);
	res.vec_col = rgb_to_vec(res.color);
	m->amb_light = res;
	return (SUCCESS);
}

int	init_camera(t_rt *m, char **args)
{
	t_camera	res;

	if (init_coordinates(&(res.coordinates), args[1]))
		return (FAILURE);
	if (init_vector(&(res.normalized), args[2]))
		return (FAILURE);
	rt_atoi(args[3], &(res.fov));
	res.aspect_ratio = m->width / (float) m->height;
	res.angle = tan(M_PI * 0.5 * res.fov / 180.0);
	m->camera = res;
	return (SUCCESS);
}

int	init_light(t_rt *m, char **args)
{
	t_light	res;

	if (init_coordinates(&(res.coordinates), args[1]))
		return (FAILURE);
	rt_atof(args[2], &(res.ratio));
	if (init_colors(&(res.color), args[3]))
		return (FAILURE);
	res.vec_col = rgb_to_vec(res.color);
	res.emission_color = (t_vector) {1,1,1};
	res.diameter = 5.f;
	m->light = res;
	return (SUCCESS);
}
