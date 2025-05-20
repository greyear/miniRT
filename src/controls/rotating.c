
#include "../../include/mini_rt.h"

static void	rotate_x(t_vector *vec, float alpha)
{
	float	previous_y;
	float	previous_z;

	previous_y = vec->y;
	previous_z = vec->z;
	vec->y = previous_y * cosf(alpha) - previous_z * sinf(alpha);
	vec->z = previous_y * sinf(alpha) + previous_z * cosf(alpha);
}

static void	rotate_y(t_vector *vec, float beta)
{
	float	previous_x;
	float	previous_z;

	previous_x = vec->x;
	previous_z = vec->z;
	vec->x = previous_x * cosf(beta) + previous_z * sinf(beta);
	vec->z = -previous_x * sinf(beta) + previous_z * cosf(beta);
}

static void	rotate_z(t_vector *vec, float gamma)
{
	float	previous_x;
	float	previous_y;

	previous_x = vec->x;
	previous_y = vec->y;
	vec->x = previous_x * cosf(gamma) - previous_y * sinf(gamma);
	vec->y = previous_x * sinf(gamma) + previous_y * cosf(gamma);
}

//again 3 axes: left/right for x, up/down for y, a/d for z
void	rotate(t_rt *rt, mlx_key_data_t keydata, t_vector rotation_vec)
{
	if (rt->obj_sel == OBJ_SEL)
	{
		if (rt->objects[rt->obj_index].type == SPHERE)
			return ;
		if (rt->objects[rt->obj_index].type == CYLINDER)
		{
			
		}
		if (rt->objects[rt->obj_index].type == PLANE)
		{
			
		}
	}
	else if (rt->obj_sel == LIGHT_SEL)
		return ;
	else if (rt->obj_sel == CAMERA_SEL) //what if 0:0:0 as a start?
	{
		float angle;

		if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_RIGHT)
		{
			angle = rotation_vec.x / 10;
			printf("before: %f, %f, %f\n", rt->camera.normalized.x, rt->camera.normalized.y, rt->camera.normalized.z);
			rotate_x(&(rt->camera.normalized), angle);
			printf("after: %f, %f, %f\n", rt->camera.normalized.x, rt->camera.normalized.y, rt->camera.normalized.z);
		}
		else if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_DOWN)
		{
			angle = rotation_vec.y / 10;
			rotate_y(&(rt->camera.normalized), angle);
		}
		else if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_D)
		{
			angle = rotation_vec.z / 10;
			rotate_z(&(rt->camera.normalized), angle);
		}
		normalize(&rt->camera.normalized);
	}
}
