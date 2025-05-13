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

#include "../../include/miniRT.h"

int	init_sphere(t_miniRT *m, char **args)
{
	t_sphere	res;
	int			i;

	if (init_coordinates(&(res.coordinates), args[1]))
		return (FAILURE);
	rt_atof(args[2], &(res.diameter));
	if (init_colors(&(res.color), args[3]))
		return (FAILURE);
	i = m->e_index[E_SPHERE];
	m->spheres[i] = res;
	m->e_index[E_SPHERE]++;
	return (SUCCESS);
}

int	init_plane(t_miniRT *m, char **args)
{
	t_plane	res;
	int		i;

	if (init_coordinates(&(res.coordinates), args[1]))
		return (FAILURE);
	if (init_vector(&(res.normalized), args[2]))
		return (FAILURE);
	if (init_colors(&(res.color), args[3]))
		return (FAILURE);
	i = m->e_index[E_PLANE];
	m->planes[i] = res;
	m->e_index[E_PLANE]++;
	return (SUCCESS);
}

int	init_cylinder(t_miniRT *m, char **args)
{
	t_cylinder	res;
	int			i;

	if (init_coordinates(&(res.coordinates), args[1]))
		return (FAILURE);
	if (init_vector(&(res.normalized), args[2]))
		return (FAILURE);
	rt_atof(args[3], &(res.diameter));
	rt_atof(args[4], &(res.height));
	if (init_colors(&(res.color), args[5]))
		return (FAILURE);
	i = m->e_index[E_CYLINDER];
	m->cylinders[i] = res;
	m->e_index[E_CYLINDER]++;
	return (SUCCESS);
}
