
#include "../../include/mini_rt.h"

//again 3 axes: left/right for x, up/down for y, a/d for z

void	rotate(t_rt *rt, mlx_key_data_t keydata, t_vector change)
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
	else if (rt->obj_sel == CAMERA_SEL)
	;
}
