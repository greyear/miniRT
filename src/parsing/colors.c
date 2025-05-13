/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:41:40 by azinchen          #+#    #+#             */
/*   Updated: 2025/05/13 12:41:43 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

/*colors [0-255] RGB int, 3 numbers
for ambient, sphere, plane, cylinder*/

int	validate_color(char *str, char *element)
{
	t_val_flags	flags;
	t_val_rules	rules;
	t_val_err	err;

	flags = VAL_INT | VAL_INT_RANGE | VAL_COMPONENTS;
	rules.flags = flags;
	rules.min_int = 0;
	rules.max_int = 255;
	rules.comp = 3;
	err = validate_value(str, rules);
	if (err != VAL_SUCCESS)
		return (print_val_err(err, element, "Color"));
	return (SUCCESS);
}

int	init_colors(t_col *color, char *three)
{
	char	**split;
	int		r;
	int		g;
	int		b;

	split = ft_split(three, ',');
	if (!split)
		return (print_err(MLLC_MSG));
	rt_atoi(split[0], &r);
	rt_atoi(split[1], &g);
	rt_atoi(split[2], &b);
	color->r = (uint8_t)r;
	color->g = (uint8_t)g;
	color->b = (uint8_t)b;
	ft_clean_arr(&split);
	return (SUCCESS);
}
