/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_cleaning.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:11:30 by azinchen          #+#    #+#             */
/*   Updated: 2025/04/09 14:17:18 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

void	struct_clean(t_miniRT *rt)
{
	if (rt->spheres)
		free(rt->spheres);
	rt->spheres = NULL;
	if (rt->planes)
		free(rt->planes);
	rt->planes = NULL;
	if (rt->cylinders)
		free(rt->cylinders);
	rt->cylinders = NULL;
}
