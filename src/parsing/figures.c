
#include "../../include/miniRT.h"

int validate_sphere(char **args)
{
	if (ft_array_len(args) != 3)
		return (print_err(SPHERE_ARGS));
}

int validate_plane(char **args)
{
	if (ft_array_len(args) != 3)
		return (print_err(PLANE_ARGS));
}

int validate_cylinder(char **args)
{
	if (ft_array_len(args) != 5)
		return (print_err(CYLINDER_ARGS));
}
