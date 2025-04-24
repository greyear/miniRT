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
	obj.light = NULL;
	obj.objects = NULL;
	obj.obj_count = 2;

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