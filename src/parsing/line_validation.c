/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:45:06 by azinchen          #+#    #+#             */
/*   Updated: 2025/05/13 12:45:08 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

static int	choose_for_validation(char *line)
{
	char	**divided;
	char	**args;
	int		res;

	res = FAILURE;
	divided = ft_split(line, ' ');
	if (!divided)
		return (print_err(MLLC_MSG));
	args = divided + 1;
	if (!ft_strcmp(divided[0], "A"))
		res = validate_ambient(args);
	else if (!ft_strcmp(divided[0], "C"))
		res = validate_camera(args);
	else if (!ft_strcmp(divided[0], "L"))
		res = validate_light(args);
	else if (!ft_strcmp(divided[0], "sp"))
		res = validate_sphere(args);
	else if (!ft_strcmp(divided[0], "pl"))
		res = validate_plane(args);
	else if (!ft_strcmp(divided[0], "cy"))
		res = validate_cylinder(args);
	ft_clean_arr(&divided);
	return (res);
}

int	validate_element_type(char *line, t_rt *m)
{
	int	i;
	int	len;

	i = 0;
	while (i < E_TYPES_AMOUNT)
	{
		len = ft_strlen(m->e_names[i]);
		if (!ft_strncmp(line, m->e_names[i], len) && line[len] == ' ')
		{
			m->e_count[i]++;
			if (ft_iscapital(m->e_names[i][0]) && m->e_count[i] > 1)
				return (print_err(DB_ELEM_MSG));
			return (choose_for_validation(line));
		}
		i++;
	}
	if (i == E_TYPES_AMOUNT)
		return (print_err(VALID_MSG));
	return (SUCCESS);
}
