/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_cleaning.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:11:30 by azinchen          #+#    #+#             */
/*   Updated: 2025/05/02 15:35:05 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

void	clean_struct(t_rt *rt)
{
	if (!rt)
		return ;
	if (rt->objects)
	{
		free(rt->objects);
		rt->objects = NULL;
	}
	if (rt->light)
	{
		free(rt->light);
		rt->light = NULL;
	}
	if (rt->camera)
	{
		free(rt->camera);
		rt->light = NULL;
	}
}

void	clean_exit(t_rt *rt)
{
	clean_struct(rt);
	printf("malloc error\n");
	exit (1);
}
