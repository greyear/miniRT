/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:42:09 by azinchen          #+#    #+#             */
/*   Updated: 2025/05/13 12:42:11 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

/*coordinates [do we have any restrictions?], flt, 3 numbers
for camera, light, sphere, plane, cylinder*/

int	validate_coordinates(char *str, char *element)
{
	t_val_flags	flags;
	t_val_rules	rules;
	t_val_err	err;

	flags = VAL_FLT | VAL_COMPONENTS;
	rules.flags = flags;
	rules.comp = 3;
	err = validate_value(str, rules);
	if (err != VAL_SUCCESS)
		return (print_val_err(err, element, "Coordinates"));
	return (SUCCESS);
}

int	init_coordinates(t_vector *coordinates, char *three)
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
	coordinates->x = x;
	coordinates->y = y;
	coordinates->z = z;
	ft_clean_arr(&split);
	return (SUCCESS);
}
