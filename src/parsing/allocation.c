/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:41:17 by azinchen          #+#    #+#             */
/*   Updated: 2025/05/13 12:41:19 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

int	allocation(t_rt *m)
{
	m->obj_count = m->e_count[E_SPHERE] + m->e_count[E_PLANE]
		+ m->e_count[E_CYLINDER];
	m->objects = ft_calloc(m->obj_count, sizeof(t_obj));
	if (!m->objects)
		return (print_err(MLLC_MSG));
	return (SUCCESS);
}
