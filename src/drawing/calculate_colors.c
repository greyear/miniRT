/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_colors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:49:50 by msavelie          #+#    #+#             */
/*   Updated: 2025/04/24 14:51:05 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

uint32_t	vec_to_rgba(t_vector color)
{
	uint8_t	r = (uint8_t)(fmax(0, fmin(1, color.x)) * 255);
	uint8_t	g = (uint8_t)(fmax(0, fmin(1, color.y)) * 255);
	uint8_t	b = (uint8_t)(fmax(0, fmin(1, color.z)) * 255);
	uint8_t	a = 255;

	return ((a << 24) | (r << 16) | (g << 8) | b);
}
