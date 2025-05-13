/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FOV.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:43:49 by azinchen          #+#    #+#             */
/*   Updated: 2025/05/13 12:43:51 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

/*FOV [0-180] int, 1 number
for camera*/

int	validate_fov(char *str, char *element)
{
	t_val_flags	flags;
	t_val_rules	rules;
	t_val_err	err;

	flags = VAL_INT | VAL_INT_RANGE | VAL_COMPONENTS;
	rules.flags = flags;
	rules.min_int = 0;
	rules.max_int = 180;
	rules.comp = 1;
	err = validate_value(str, rules);
	if (err != VAL_SUCCESS)
		return (print_val_err(err, element, "FOV"));
	return (SUCCESS);
}
