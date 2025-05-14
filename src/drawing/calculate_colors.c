/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_colors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:49:50 by msavelie          #+#    #+#             */
/*   Updated: 2025/05/14 16:49:27 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

uint32_t	vec_to_rgba(t_vector color)
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	a;

	r = (uint8_t)(fmax(0, fmin(1, color.x)) * 255);
	g = (uint8_t)(fmax(0, fmin(1, color.y)) * 255);
	b = (uint8_t)(fmax(0, fmin(1, color.z)) * 255);
	a = 255;
	return ((r << 24) | (g << 16) | (b << 8) | a);
}

t_vector	rgb_to_vec(t_col color)
{
	t_vector	vec;

	vec.x = (float) ((float) color.r / 255);
	vec.y = (float) ((float) color.g / 255);
	vec.z = (float) ((float) color.b / 255);
	return (vec);
}
