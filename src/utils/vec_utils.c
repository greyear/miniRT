/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:23:59 by msavelie          #+#    #+#             */
/*   Updated: 2025/04/23 16:33:24 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

inline t_vector vec_add(t_vector vec1, t_vector vec2)
{
	return ((t_vector) { vec1.x + vec2.x, vec1.y + vec2.y, vec1.z + vec2.z });
}

inline t_vector vec_sub(t_vector vec1, t_vector vec2)
{
	return ((t_vector) { vec1.x - vec2.x, vec1.y - vec2.y, vec1.z - vec2.z });
}

inline t_vector vec_mul(t_vector vec1, t_vector vec2)
{
	return ((t_vector) { vec1.x * vec2.x, vec1.y * vec2.y, vec1.z * vec2.z });
}

inline t_vector vec_mul_num(t_vector vec1, double num)
{
	return ((t_vector) { vec1.x * num, vec1.y * num, vec1.z * num });
}

inline t_vector vec_sub_num(t_vector vec1, double num)
{
	return ((t_vector) { vec1.x - num, vec1.y - num, vec1.z - num });
}
