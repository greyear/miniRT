/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_figure.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:48:29 by msavelie          #+#    #+#             */
/*   Updated: 2025/04/09 16:22:05 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

void	draw_figure(void)
{
	uint32_t color = rgb_to_rgba(0xff0000);
	mlx_t *obj = mlx_init(WIN_WIDTH, WIN_HEIGHT, "miniRT", true);
	mlx_image_t *img = mlx_new_image(obj, WIN_WIDTH, WIN_HEIGHT);
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			mlx_put_pixel(img, i, j, color);
		}
	}
	mlx_image_to_window(obj, img, 100, 100);
	mlx_loop(obj);
	mlx_terminate(obj);
}

