
#include "../../include/miniRT.h"

int	init_ambient(t_miniRT *m, char **args)
{
	t_ambient	res;

	rt_atof(args[1], &(res.ratio));
	if (init_color(&(res.color), args[2]))
		return (FAILURE);
	m->amb_light = res;
	return (SUCCESS);
}

int	init_camera(t_miniRT *m, char **args)
{

	return (SUCCESS);
}

int	init_light(t_miniRT *m, char **args)
{

	return (SUCCESS);
}
