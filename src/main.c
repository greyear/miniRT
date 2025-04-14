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
	const char	*e_names[E_TYPES_AMOUNT];

	e_names[0] = "A";
	e_names[1] = "C",
	e_names[2] = "L",
	e_names[3] = "sp",
	e_names[4] = "pl",
	e_names[5] = "cy";
	ft_bzero(m, sizeof(*m));
	ft_memcpy(m->e_names, e_names, sizeof(e_names));
}

int main()
{
	t_miniRT	m; //allocate?

	init_minirt(&m);
	
	/*
	if arg_check(argc)
		return (1);
	else
		
		*/
	draw_figure();
	return (0);
}