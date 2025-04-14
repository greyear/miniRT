/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_figure.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:48:29 by msavelie          #+#    #+#             */
/*   Updated: 2025/04/14 14:42:29 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

void	draw_figure(t_vector *image)
{
	mlx_t *obj = mlx_init(WIN_WIDTH, WIN_HEIGHT, "miniRT", true);
	mlx_image_t *img = mlx_new_image(obj, WIN_WIDTH, WIN_HEIGHT);
	for (int y = 0; y < WIN_HEIGHT; y++) {
		for (int x = 0; x < WIN_WIDTH; x++) {
			mlx_put_pixel(img, x, y, vec_to_rgb(image[x + WIN_WIDTH * y]));
			// printf("x: %d, y: %d\n", x, y);
		}
	}
	mlx_image_to_window(obj, img, 0, 0);
	mlx_loop(obj);
	mlx_terminate(obj);
}

