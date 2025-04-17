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

double	length2(t_vector vec)
{
	return (pow(vec.x, 2) + pow(vec.y, 2) + pow(vec.z, 2));
}

t_vector	revert_vector(t_vector vec)
{
	return ((t_vector) {-vec.x, -vec.y, -vec.z});
}

double	dot(t_vector vec1, t_vector vec2)
{
	return (vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z);
}

t_vector	calculate_with_vector(t_vector vec1, t_vector vec2, t_calc operation)
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

double	lerp(double a, double b, double mix)
{
	return (b * mix + a * (1 - mix));
}

t_vector	calculate_with_number(t_vector vec, double num, t_calc operation)
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

double	min(double a, double b)
{
	if (a < b)
		return (a);
	return (b);
}

double	max(double a, double b)
{
	if (a > b)
		return (a);
	return (b);
}
