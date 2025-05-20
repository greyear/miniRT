/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:45:40 by msavelie          #+#    #+#             */
/*   Updated: 2025/05/20 16:45:34 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

void	main_hook(void *obj)
{
	t_rt	*rt;

	rt = (t_rt *) obj;
	if (rt->needs_render == 1)
	{
		create_img(rt);
		mlx_resize_image(rt->mlx_img, rt->width, rt->height);
		render(rt);
		draw_pixels(rt);
		rt->needs_render = 0;
	}
	else if (rt->needs_render == 2)
		draw_gui(rt);
}

//instructions what to change
static void	transform(t_rt *rt, mlx_key_data_t keydata, t_vector change)
{
	if (rt->mode == MOVE)
		move(rt, change);
	if (rt->mode == SCALE)
		scale(rt, keydata, change);
	if (rt->mode == ROTATE)
		rotate(rt, keydata, change);
	rt->needs_render = 1;
}

void	keys_hook(mlx_key_data_t keydata, void *obj)
{
	t_rt	*rt;

	rt = (t_rt *) obj;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(rt->mlx);
	if (keydata.key == MLX_KEY_O && keydata.action == MLX_RELEASE
		&& rt->needs_render == 0)
			select_objects(rt);
	else if (keydata.key == MLX_KEY_L && keydata.action == MLX_RELEASE
		&& rt->needs_render == 0)
		select_light(rt);
	else if (keydata.key == MLX_KEY_C && keydata.action == MLX_RELEASE
		&& rt->needs_render == 0)
		select_camera(rt);
	else if (keydata.key == MLX_KEY_M && keydata.action == MLX_RELEASE
		&& rt->needs_render == 0)
		set_move_mode(rt);
	else if (keydata.key == MLX_KEY_R && keydata.action == MLX_RELEASE
		&& rt->needs_render == 0)
		set_rotate_mode(rt);
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE
		&& rt->needs_render == 0)
		set_scale_mode(rt);
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		transform(rt, keydata, (t_vector) {-1,0,0});
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		transform(rt, keydata, (t_vector) {1,0,0});
	else if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		transform(rt, keydata, (t_vector) {0,1,0});
	else if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		transform(rt, keydata, (t_vector) {0,-1,0});
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		transform(rt, keydata, (t_vector) {0,0,-1}); //or better vice versa?
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		transform(rt, keydata, (t_vector) {0,0,1});
}

void	win_resize(int width, int height, void *param)
{
	t_rt	*rt;

	rt = (t_rt *) param;
	rt->width = width;
	rt->height = height;
	rt->needs_render = 1;
	rt->camera.aspect_ratio = rt->width / (float)rt->height;
}
