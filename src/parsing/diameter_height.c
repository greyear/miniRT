/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diameter_height.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:43:20 by azinchen          #+#    #+#             */
/*   Updated: 2025/05/13 12:43:22 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"
#include <float.h>

/*diameter/height [0.0, unlimited], 1 number
for sphere, cylinder*/

int	validate_diameter_height(char *str, char *element)
{
	t_val_flags	flags;
	t_val_rules	rules;
	t_val_err	err;

	flags = VAL_FLT | VAL_FLT_RANGE | VAL_COMPONENTS;
	rules.flags = flags;
	rules.min_flt = 0.0;
	rules.max_flt = FLT_MAX; //?
	rules.comp = 1;
	err = validate_value(str, rules);
	if (err != VAL_SUCCESS)
		return (print_val_err(err, element, "Diameter/height"));
	return (SUCCESS);
}
