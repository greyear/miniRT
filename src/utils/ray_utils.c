/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:25:02 by msavelie          #+#    #+#             */
/*   Updated: 2025/05/18 16:54:35 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

inline float	lerp(float a, float b, float mix)
{
	return (b * mix + a * (1 - mix));
}

inline void	clamp(t_vector *pixel)
{
	if (pixel->x < 0)
		pixel->x = 0;
	else if (pixel->x > 1)
		pixel->x = 1;
	if (pixel->y < 0)
		pixel->y = 0;
	else if (pixel->y > 1)
		pixel->y = 1;
	if (pixel->z < 0)
		pixel->z = 0;
	else if (pixel->z > 1)
		pixel->z = 1;
}
