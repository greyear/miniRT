/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:25:02 by msavelie          #+#    #+#             */
/*   Updated: 2025/04/14 15:27:04 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

inline float	length2(t_vector vec)
{
	return (pow(vec.x, 2) + pow(vec.y, 2) + pow(vec.z, 2));
}

inline t_vector	revert_vector(t_vector vec)
{
	return ((t_vector) {-vec.x, -vec.y, -vec.z});
}

inline float	dot(t_vector vec1, t_vector vec2)
{
	return (vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z);
}

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
