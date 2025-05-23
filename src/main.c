/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:35:19 by msavelie          #+#    #+#             */
/*   Updated: 2025/05/20 17:05:22 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini_rt.h"

void	create_img(t_rt *rt)
{
	if (rt->image)
		free(rt->image);
	rt->image = malloc(rt->width * rt->height * sizeof(t_vector));
	if (!rt->image)
		clean_exit(rt);
}

static t_rt	init_struct(void)
{
	t_rt	rt;

	ft_bzero(&rt, sizeof(rt));
	rt.width = WIN_WIDTH;
	rt.height = WIN_HEIGHT;
	rt.mlx = NULL;
	rt.image = NULL;
	create_img(&rt);
	rt.needs_render = 0;
	rt.cur_index = 0;
	rt.obj_index = 0;
	return (rt);
}

static void	init_e_names(t_rt *rt)
{
	rt->e_names[0] = "A";
	rt->e_names[1] = "C";
	rt->e_names[2] = "L";
	rt->e_names[3] = "sp";
	rt->e_names[4] = "pl";
	rt->e_names[5] = "cy";
}

int	main(int argc, char *argv[])
{
	t_rt	rt;

	rt = init_struct();
	init_e_names(&rt);
	if (validation(&rt, argc, argv))
	{
		clean_struct(&rt);
		return (FAILURE);
	}
	if (allocation(&rt))
	{
		clean_struct(&rt);
		return (FAILURE);
	}
	if (init(&rt, argv[1]))
	{
		clean_struct(&rt);
		return (FAILURE);
	}
	render(&rt);
	draw_figure(&rt);
	clean_struct(&rt);
	return (SUCCESS);
}
