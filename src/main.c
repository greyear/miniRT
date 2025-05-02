/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:35:19 by msavelie          #+#    #+#             */
/*   Updated: 2025/05/02 15:31:18 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini_rt.h"

static t_rt	init_struct(void)
{
	t_rt		obj;

	obj.mlx = NULL;
	obj.amb_light = NULL;
	obj.camera = init_camera();
	obj.obj_count = 3;
	obj.objects = init_objects(&obj);
	obj.light = init_light(&obj);
	obj.ambient_light = (t_vector) {0.1, 0.1, 0.1};

	return (obj);
}

int main(void)
{
	t_rt		obj;
	t_vector	*image;

	obj = init_struct();
	image = render(&obj);
	draw_figure(image, &obj);
	clean_struct(&obj);
	return (0);
}
