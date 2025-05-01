
#include "../../include/miniRT.h"

int	if_out_of_range(char *str, double min, double max)
{
	double	value;

	if (rt_atod(str, &value) == 1)
		return (FAILURE);
	if (value < min || value > max)
		return (FAILURE);
	return (SUCCESS);
}

