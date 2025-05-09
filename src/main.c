/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:35:19 by msavelie          #+#    #+#             */
/*   Updated: 2025/05/05 16:48:53 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini_rt.h"

void	create_img(t_rt *rt)
{
	if (rt->image)
		free(rt->image);
	rt->image = malloc(rt->width * rt->height * sizeof(t_vector));
	if (!rt->image)
		clean_exit(rt);
}

static t_rt	init_struct(void)
{
	t_rt	rt;

	rt.width = WIN_WIDTH;
	rt.height = WIN_HEIGHT;
	rt.mlx = NULL;
	rt.amb_light = NULL;
	rt.camera = init_camera();
	rt.obj_count = 3;
	rt.objects = init_objects(&rt);
	rt.light = init_light(&rt);
	rt.ambient_light = (t_vector) {0.1, 0.1, 0.1};
	rt.image = NULL;
	create_img(&rt);
	rt.needs_render = 0;
	return (rt);
}

size_t	get_time(void) //deleteme
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int main(void)
{
	t_rt		rt;

	rt = init_struct();
	size_t	time = get_time();
	render(&rt);
	printf("%zu\n", get_time() - time);
	draw_figure(&rt);
	clean_struct(&rt);
	return (0);
}
