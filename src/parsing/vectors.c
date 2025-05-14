/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:49:03 by azinchen          #+#    #+#             */
/*   Updated: 2025/05/13 12:49:05 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

/*3d normalized vector [-1.0,1.0] float, 3 numbers
for camera, plane, cylinder*/

int	validate_vector(char *str, char *element)
{
	t_val_flags	flags;
	t_val_rules	rules;
	t_val_err	err;

	flags = VAL_FLT | VAL_FLT_RANGE | VAL_COMPONENTS;
	rules.flags = flags;
	rules.min_flt = -1.0;
	rules.max_flt = 1.0;
	rules.comp = 3;
	err = validate_value(str, rules);
	if (err != VAL_SUCCESS)
		return (print_val_err(err, element, "Vector"));
	return (SUCCESS);
}

//in case of future changes saved this one but it's similar to coordinates
int	init_vector(t_vector *vector, char *three)
{
	char	**split;
	float	x;
	float	y;
	float	z;

	split = ft_split(three, ',');
	if (!split)
		return (print_err(MLLC_MSG));
	rt_atof(split[0], &x);
	rt_atof(split[1], &y);
	rt_atof(split[2], &z);
	vector->x = x;
	vector->y = y;
	vector->z = z;
	ft_clean_arr(&split);
	return (SUCCESS);
}
