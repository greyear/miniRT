/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_figure.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:48:29 by msavelie          #+#    #+#             */
/*   Updated: 2025/05/17 17:53:54 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

void	draw_pixels(t_rt *rt)
{
	int			x;
	int			y;
	uint32_t	color;

	y = 0;
	while (y < rt->height)
	{
		x = 0;
		while (x < rt->width)
		{
			color = vec_to_rgba(rt->image[x + rt->width * y]);
			mlx_put_pixel(rt->mlx_img, x, y, color);
			x++;
		}
		y++;
	}
}

void	draw_figure(t_rt *rt)
{
	size_t time = get_time();
	rt->mlx = mlx_init(rt->width, rt->height, "miniRT", true);
	mlx_set_window_limit(rt->mlx, 300, 150, 3000, 2000);
	mlx_image_t *img = mlx_new_image(rt->mlx, rt->width, rt->height);
	rt->mlx_img = img;
	draw_pixels(rt);
	mlx_image_to_window(rt->mlx, img, 0, 0);
	draw_gui(rt);
	printf("%zu\n", get_time() - time);
	mlx_key_hook(rt->mlx, keys_hook, rt);
	mlx_loop_hook(rt->mlx, main_hook, rt);
	mlx_resize_hook(rt->mlx, win_resize, rt);
	mlx_loop(rt->mlx);
	mlx_terminate(rt->mlx);
}

