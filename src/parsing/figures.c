
#include "../../include/miniRT.h"

int validate_sphere(char **args)
{
	if (ft_array_len(args) != 3)
		return (print_err(SPHERE_ARGS));
	if (validate_coordinates(args[0]))
		return (FAILURE);
	if (validate_diameter_height(args[1]))
		return (FAILURE);
	if (validate_color(args[2]))
		return (FAILURE);
	return (SUCCESS);
}

int validate_plane(char **args)
{
	if (ft_array_len(args) != 3)
		return (print_err(PLANE_ARGS));
	if (validate_coordinates(args[0]))
		return (FAILURE);
	if (validate_vector(args[1]))
		return (FAILURE);
	if (validate_color(args[2]))
		return (FAILURE);
	return (SUCCESS);
}

int validate_cylinder(char **args)
{
	if (ft_array_len(args) != 5)
		return (print_err(CYLINDER_ARGS));
	if (validate_coordinates(args[0]))
		return (FAILURE);
	if (validate_vector(args[1]))
		return (FAILURE);
	if (validate_diameter_height(args[2]))
		return (FAILURE);
	if (validate_diameter_height(args[3]))
		return (FAILURE);
	if (validate_color(args[4]))
		return (FAILURE);
	return (SUCCESS);
}
