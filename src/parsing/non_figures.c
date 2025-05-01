
#include "../../include/miniRT.h"

int validate_ambient(char **args)
{
	if (ft_array_len(args) != 2)
		return (print_err(AMBIENT_ARGS));
}

int validate_camera(char **args)
{
	if (ft_array_len(args) != 3)
		return (print_err(CAMERA_ARGS));
}

int validate_light(char **args)
{
	if (ft_array_len(args) != 2) //without bonus
		return (print_err(LIGHT_ARGS));
}
