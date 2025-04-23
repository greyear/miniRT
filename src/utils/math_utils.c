/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:19:35 by msavelie          #+#    #+#             */
/*   Updated: 2025/04/23 17:21:13 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

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

inline float	random_float_fast(unsigned int *seed)
{
	*seed ^= *seed << 13;
	*seed ^= *seed >> 17;
	*seed ^= *seed << 5;
	return (*seed & 0xFFFFFF) / (float)0xFFFFFF;
}
