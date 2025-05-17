/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:45:40 by msavelie          #+#    #+#             */
/*   Updated: 2025/05/17 15:47:05 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

void	keys_hook(void *obj)
{
	t_rt	*rt;

	rt = (t_rt *) obj;
	if (mlx_is_key_down(rt->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(rt->mlx);
	if (mlx_is_key_down(rt->mlx, MLX_KEY_O))
		select_objects(rt);
	if (rt->needs_render == 1)
	{
		create_img(rt);
		mlx_resize_image(rt->mlx_img, rt->width, rt->height);
		render(rt);
		draw_pixels(rt);
		draw_gui(rt);
		rt->needs_render = 0;
	}
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
