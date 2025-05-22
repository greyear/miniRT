#include "../../include/mini_rt.h"

static void	selection_keys(t_rt *rt, mlx_key_data_t keydata)
{
	if (keydata.key == MLX_KEY_O)
		select_objects(rt);
	else if (keydata.key == MLX_KEY_L)
		select_light(rt);
	else if (keydata.key == MLX_KEY_C)
		select_camera(rt);
	else if (keydata.key == MLX_KEY_M)
		set_move_mode(rt);
	else if (keydata.key == MLX_KEY_R)
		set_rotate_mode(rt);
	else if (keydata.key == MLX_KEY_S)
		set_scale_mode(rt);
}

static void	transform_keys(t_rt *rt, mlx_key_data_t keydata)
{
	if (keydata.key == MLX_KEY_LEFT)
		transform(rt, keydata, (t_vector){-1, 0, 0});
	else if (keydata.key == MLX_KEY_RIGHT)
		transform(rt, keydata, (t_vector){1, 0, 0});
	else if (keydata.key == MLX_KEY_UP)
		transform(rt, keydata, (t_vector){0, 1, 0});
	else if (keydata.key == MLX_KEY_DOWN)
		transform(rt, keydata, (t_vector){0, -1, 0});
	else if (keydata.key == MLX_KEY_A)
		transform(rt, keydata, (t_vector){0, 0, -1});
	else if (keydata.key == MLX_KEY_D)
		transform(rt, keydata, (t_vector){0, 0, 1});
}

void	keys_hook(mlx_key_data_t keydata, void *obj)
{
	t_rt	*rt;

	rt = (t_rt *) obj;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(rt->mlx);
	else if (keydata.action == MLX_RELEASE && rt->needs_render == 0)
		selection_keys(rt, keydata);
	else if (keydata.action == MLX_PRESS)
		transform_keys(rt, keydata);
}
