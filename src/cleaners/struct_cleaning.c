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
	//another fields
	if (rt->spheres)
		free(rt->spheres);
	if (rt->planes)
		free(rt->planes);
	if (rt->cylinders)
		free(rt->cylinders);
	if (rt->fd >= 0)
		close(rt->fd);
	/*if (rt)
		free(rt); as we're not allocating rt in main, but just have it in stack*/ 
}
