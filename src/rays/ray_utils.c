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

#include "../../include/miniRT.h"

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

inline t_vector	calculate_with_vector(t_vector vec1, t_vector vec2, t_calc operation)
{
	t_vector	result;
	if (operation == ADD)
		result = (t_vector) {vec1.x + vec2.x, vec1.y + vec2.y, vec1.z + vec2.z};
	else if (operation == SUBTRACT)
		result = (t_vector) {vec1.x - vec2.x, vec1.y - vec2.y, vec1.z - vec2.z};
	else if (operation == MULTIPLY)
		result = (t_vector) {vec1.x * vec2.x, vec1.y * vec2.y, vec1.z * vec2.z};
	else
		result = (t_vector) {vec1.x / vec2.x, vec1.y / vec2.y, vec1.z / vec2.z};
	return (result);
}

inline t_vector	calculate_with_number(t_vector vec, float num, t_calc operation)
{
	t_vector	result;

	result = vec;
	if (operation == ADD)
		result = (t_vector) {vec.x + num, vec.y + num, vec.z + num};
	else if (operation == SUBTRACT)
		result = (t_vector) {vec.x - num, vec.y - num, vec.z - num};
	else if (operation == MULTIPLY)
		result = (t_vector) {vec.x * num, vec.y * num, vec.z * num};
	else
	{
		if (num > 0)
		result = (t_vector) {vec.x / num, vec.y / num, vec.z / num};
	}
	return (result);
}

inline float	lerp(float a, float b, float mix)
{
	return (b * mix + a * (1 - mix));
}

inline float	min(float a, float b)
{
	if (a < b)
		return (a);
	return (b);
}

inline float	max(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
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

inline float	random_float(void)
{
	return (float)rand() / (float)(RAND_MAX + 1.0f);
}
