/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:35:19 by msavelie          #+#    #+#             */
/*   Updated: 2025/04/17 15:34:19 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini_rt.h"

static t_miniRT	init_struct(void)
{
	t_miniRT	obj;

	obj.mlx = NULL;
	obj.amb_light = NULL;
	obj.camera = ft_calloc(1, sizeof(t_camera));
	if (!obj.camera)
	{
		printf("Malloc error\n");
		exit(1);
	}
	obj.camera->coordinates = (t_vector) {0, 0, 0};
	obj.obj_count = 3;
	obj.objects = ft_calloc(obj.obj_count, sizeof(t_obj));
	if (!obj.objects)
	{
		printf("Malloc error\n");
		exit(1);
	}
	t_vector  em_color = {0, 0, 0};
	obj.objects[0] = init_obj((t_vector) {0, -2, -20}, em_color, SPHERE);
	obj.objects[1] = init_obj((t_vector) {-5, -7, -25}, em_color, CYLINDER);
	obj.objects[2] = init_obj((t_vector) {0, -10, 0}, em_color, PLANE);
	obj.light = ft_calloc(1, sizeof(t_light));
	if (!obj.light)
	{
		printf("Malloc error\n");
		exit(1);
	}
	init_light(obj.light);

	return (obj);
}

int main()
{
	t_miniRT	obj;
	t_vector	*image;

	obj = init_struct();
	image = render(&obj);
	draw_figure(image, &obj);
	clean_struct(&obj);
	return (0);
}