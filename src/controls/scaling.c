
#include "../../include/mini_rt.h"

static float	float_add(float fl1, float fl2)
{
	float	res;

	res = fl1 + fl2;
	if (res >= 0.00001f)
		return (res);
	else
		return (0.0f);
}

//resize diameter for a sphere and width and height for a cylinder
void	scale(t_rt *rt, mlx_key_data_t keydata, t_vector change) //set limits?
{
	if (rt->obj_sel == OBJ_SEL)
	{
		if (rt->objects[rt->obj_index].type == SPHERE)
		{
			if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_DOWN)
				rt->objects[rt->obj_index].diameter = float_add(rt->objects[rt->obj_index].diameter, change.y);
		}
		if (rt->objects[rt->obj_index].type == CYLINDER)
		{
			if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_DOWN)
				rt->objects[rt->obj_index].height = float_add(rt->objects[rt->obj_index].height, change.y);
			if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_RIGHT)
				rt->objects[rt->obj_index].radius = float_add(rt->objects[rt->obj_index].radius, change.x / 2);
		}
	}
	else if (rt->obj_sel == LIGHT_SEL)
		return ;
	else if (rt->obj_sel == CAMERA_SEL)
		return ;
}
