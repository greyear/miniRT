
#include "../../include/miniRT.h"

int	validate_ambient(char **args)
{
	if (ft_array_len(args) != 2)
		return (print_err(AMBIENT_ARGS));
	if (validate_ratio(args[0], "Ambient"))
		return (FAILURE);
	if (validate_color(args[1], "Ambient"))
		return (FAILURE);
	return (SUCCESS);
}

int	validate_camera(char **args)
{
	if (ft_array_len(args) != 3)
		return (print_err(CAMERA_ARGS));
	if (validate_coordinates(args[0], "Camera"))
		return (FAILURE);
	if (validate_vector(args[1], "Camera"))
		return (FAILURE);
	if (validate_fov(args[2], "Camera"))
		return (FAILURE);
	return (SUCCESS);
}

int	validate_light(char **args)
{
	if (ft_array_len(args) != 3) //including color, but what if we have no?
		return (print_err(LIGHT_ARGS));
	if (validate_coordinates(args[0], "Light"))
		return (FAILURE);
	if (validate_ratio(args[1], "Light"))
		return (FAILURE);
	if (validate_color(args[2], "Light"))
		return (FAILURE);
	return (SUCCESS);
}
