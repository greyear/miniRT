/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_non_figures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:44:28 by azinchen          #+#    #+#             */
/*   Updated: 2025/05/13 12:44:30 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

int	init_ambient(t_miniRT *m, char **args)
{
	t_ambient	res;

	rt_atof(args[1], &(res.ratio));
	if (init_colors(&(res.color), args[2]))
		return (FAILURE);
	m->amb_light = res;
	return (SUCCESS);
}

int	init_camera(t_miniRT *m, char **args)
{
	t_camera	res;

	if (init_coordinates(&(res.coordinates), args[1]))
		return (FAILURE);
	if (init_vector(&(res.normalized), args[2]))
		return (FAILURE);
	rt_atoi(args[3], &(res.view_field));
	m->camera = res;
	return (SUCCESS);
}

int	init_light(t_miniRT *m, char **args)
{
	t_light	res;

	if (init_coordinates(&(res.coordinates), args[1]))
		return (FAILURE);
	rt_atof(args[2], &(res.ratio));
	if (init_colors(&(res.color), args[3]))
		return (FAILURE);
	m->light = res;
	return (SUCCESS);
}
