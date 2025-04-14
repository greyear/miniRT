/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_figure.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:48:29 by msavelie          #+#    #+#             */
/*   Updated: 2025/04/14 14:59:08 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

void	draw_figure(t_vector *image, t_miniRT *obj)
{
	uint32_t color;
	obj->mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "miniRT", true);
	mlx_image_t *img = mlx_new_image(obj->mlx, WIN_WIDTH, WIN_HEIGHT);
	for (int y = 0; y < WIN_HEIGHT; y++) {
		for (int x = 0; x < WIN_WIDTH; x++) {
			color = vec_to_rgba(image[x + WIN_WIDTH * y]);
			mlx_put_pixel(img, x, y, color);
			// printf("x: %d, y: %d\n", x, y);
		}
	}
	mlx_image_to_window(obj->mlx, img, 0, 0);
	mlx_loop_hook(obj->mlx, keys_hook, obj);
	mlx_loop(obj->mlx);
	mlx_terminate(obj->mlx);
}

