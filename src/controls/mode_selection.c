/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode_selection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 17:50:57 by msavelie          #+#    #+#             */
/*   Updated: 2025/05/17 17:53:57 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

void	set_move_mode(t_rt *rt)
{
	rt->mode = MOVE;
	rt->needs_render = 2;
}

void	set_rotate_mode(t_rt *rt)
{
	rt->mode = ROTATE;
	rt->needs_render = 2;
}

void	set_scale_mode(t_rt *rt)
{
	rt->mode = SCALE;
	rt->needs_render = 2;
}