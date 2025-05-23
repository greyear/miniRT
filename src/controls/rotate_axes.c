/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_axes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:12:42 by azinchen          #+#    #+#             */
/*   Updated: 2025/05/21 13:12:44 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

void	rotate_x(t_vector *vec, float alpha)
{
	float	previous_y;
	float	previous_z;

	previous_y = vec->y;
	previous_z = vec->z;
	vec->y = previous_y * cosf(alpha) - previous_z * sinf(alpha);
	vec->z = previous_y * sinf(alpha) + previous_z * cosf(alpha);
}

void	rotate_y(t_vector *vec, float beta)
{
	float	previous_x;
	float	previous_z;

	previous_x = vec->x;
	previous_z = vec->z;
	vec->x = previous_x * cosf(beta) + previous_z * sinf(beta);
	vec->z = -previous_x * sinf(beta) + previous_z * cosf(beta);
}

void	rotate_z(t_vector *vec, float gamma)
{
	float	previous_x;
	float	previous_y;

	previous_x = vec->x;
	previous_y = vec->y;
	vec->x = previous_x * cosf(gamma) - previous_y * sinf(gamma);
	vec->y = previous_x * sinf(gamma) + previous_y * cosf(gamma);
}
