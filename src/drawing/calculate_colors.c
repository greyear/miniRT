/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_colors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:49:50 by msavelie          #+#    #+#             */
/*   Updated: 2025/04/14 14:26:59 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

uint32_t	rgb_to_rgba(uint32_t color)
{
	uint8_t		r;
	uint8_t		g;
	uint8_t		b;
	uint32_t	rgba;

	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = color & 0xFF;
	rgba = r | (g << 16) | (b << 8) | (0xFF << 24);
	return (rgba);
}

static t_color	init_color(int start_col, int end_col)
{
	t_color	color;

	color.start_col = start_col;
	color.end_col = end_col;
	color.a_start = (start_col >> 24) & 0xFF;
	color.r_start = (start_col >> 16) & 0xFF;
	color.g_start = (start_col >> 8) & 0xFF;
	color.b_start = start_col & 0xFF;
	color.a_end = (end_col >> 24) & 0xFF;
	color.r_end = (end_col >> 16) & 0xFF;
	color.g_end = (end_col >> 8) & 0xFF;
	color.b_end = end_col & 0xFF;
	return (color);
}

uint32_t	gradient(int fst_color, int lst_color, int steps, int cur_step)
{
	t_color	color;
	float	step_a;
	float	step_r;
	float	step_g;
	float	step_b;

	color = init_color(fst_color, lst_color);
	step_a = (color.a_end - color.a_start) / (float)steps;
	step_r = (color.r_end - color.r_start) / (float)steps;
	step_g = (color.g_end - color.g_start) / (float)steps;
	step_b = (color.b_end - color.b_start) / (float)steps;
	color.cur_color = 0
		| (((uint8_t)(color.a_start
					+ (steps - cur_step) * step_a) & 0xFF) << 24)
		| (((uint8_t)(color.r_start
					+ (steps - cur_step) * step_r) & 0xFF) << 16)
		| (((uint8_t)(color.g_start
					+ (steps - cur_step) * step_g) & 0xFF) << 8)
		| (((uint8_t)(color.b_start
					+ (steps - cur_step) * step_b) & 0xFF) << 0);
	return (color.cur_color);
}

uint32_t	vec_to_rgb(t_vector color)
{
	uint8_t		r;
	uint8_t		g;
	uint8_t		b;
	uint32_t	rgba;

	r = ((int)(min(0, color.x) * 255) >> 16) & 0xFF;
	g = ((int)(min(0, color.y) * 255) >> 8) & 0xFF;
	b = (int)(min(0, color.z) * 255) & 0xFF;
	rgba = r | (g << 16) | (b << 8) | (0xFF << 24);
	return (rgba);
}
