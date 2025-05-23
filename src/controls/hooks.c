/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:45:40 by msavelie          #+#    #+#             */
/*   Updated: 2025/05/24 12:55:34 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

void	main_hook(void *obj)
{
	t_rt	*rt;

	rt = (t_rt *) obj;
	if (rt->needs_render == 1)
	{
		create_img(rt);
		if (!mlx_resize_image(rt->mlx_img, rt->width, rt->height))
		{
			mlx_close_window(rt->mlx);
			return ;
		}
		render(rt);
		draw_pixels(rt);
		rt->needs_render = 0;
	}
	else if (rt->needs_render == 2)
		if (!draw_gui(rt))
			mlx_close_window(rt->mlx);
}

void	transform(t_rt *rt, mlx_key_data_t keydata, t_vector change)
{
	if (rt->mode == MOVE)
		move(rt, change);
	if (rt->mode == SCALE)
		scale(rt, keydata, change);
	if (rt->mode == ROTATE)
		rotate(rt, keydata, change);
	rt->needs_render = 1;
}

void	win_resize(int width, int height, void *param)
{
	t_rt	*rt;

	rt = (t_rt *) param;
	rt->width = width;
	rt->height = height;
	rt->needs_render = 1;
	rt->camera.aspect_ratio = rt->width / (float)rt->height;
}
