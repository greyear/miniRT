
#include "../../include/miniRT.h"

int	validate_sphere(char **args)
{
	if (ft_array_len(args) != 3)
		return (print_err(SPHERE_ARGS));
	if (validate_coordinates(args[0], "Sphere"))
		return (FAILURE);
	if (validate_diameter_height(args[1], "Sphere"))
		return (FAILURE);
	if (validate_color(args[2], "Sphere"))
		return (FAILURE);
	return (SUCCESS);
}

int	validate_plane(char **args)
{
	if (ft_array_len(args) != 3)
		return (print_err(PLANE_ARGS));
	if (validate_coordinates(args[0], "Plane"))
		return (FAILURE);
	if (validate_vector(args[1], "Plane"))
		return (FAILURE);
	if (validate_color(args[2], "Plane"))
		return (FAILURE);
	return (SUCCESS);
}

int	validate_cylinder(char **args)
{
	if (ft_array_len(args) != 5)
		return (print_err(CYLINDER_ARGS));
	if (validate_coordinates(args[0], "Cylinder"))
		return (FAILURE);
	if (validate_vector(args[1], "Cylinder"))
		return (FAILURE);
	if (validate_diameter_height(args[2], "Cylinder"))
		return (FAILURE);
	if (validate_diameter_height(args[3], "Cylinder"))
		return (FAILURE);
	if (validate_color(args[4], "Cylinder"))
		return (FAILURE);
	return (SUCCESS);
}
