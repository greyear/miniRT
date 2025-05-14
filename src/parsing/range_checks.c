
#include "../../include/mini_rt.h"

t_val_err	int_out_of_range(char *str, int min, int max)
{
	int	value;

	if (rt_atoi(str, &value) == 1)
		return (VAL_ERR_ATON);
	if (value < min || value > max)
		return (VAL_ERR_RANGE);
	return (VAL_SUCCESS);
}

t_val_err	flt_out_of_range(char *str, float min, float max)
{
	float	value;

	if (rt_atof(str, &value) == 1)
		return (VAL_ERR_ATON);
	if (value < min || value > max)
		return (VAL_ERR_RANGE);
	return (VAL_SUCCESS);
}
