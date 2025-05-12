/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:35:19 by msavelie          #+#    #+#             */
/*   Updated: 2025/04/14 15:49:08 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

void	init_minirt(t_miniRT *m)
{
	ft_bzero(m, sizeof(*m));

	m->e_names[0] = "A";
	m->e_names[1] = "C",
	m->e_names[2] = "L",
	m->e_names[3] = "sp",
	m->e_names[4] = "pl",
	m->e_names[5] = "cy";
}

int main(int argc, char *argv[])
{
	t_miniRT	m; //allocate?

	init_minirt(&m);
	
	if (validation(&m, argc, argv))
	{
		struct_clean(&m);
		return (FAILURE);
	}
	if (allocation(&m))
	{
		struct_clean(&m);
		return (FAILURE);
	}
	if (init(&m))
	{
		struct_clean(&m);
		return (FAILURE);
	}
	
	draw_figure();
	struct_clean(&m);
	return (SUCCESS);
}
