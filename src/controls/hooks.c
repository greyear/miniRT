/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:45:40 by msavelie          #+#    #+#             */
/*   Updated: 2025/04/14 14:53:51 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

void	keys_hook(void *obj)
{
	t_miniRT	*instance;

	instance = (t_miniRT *) obj;
	if (mlx_is_key_down(instance->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(instance->mlx);
}
