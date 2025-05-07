
#include "../../include/miniRT.h"

/*3d normalized vector [-1.0,1.0] double, 3 numbers
for camera, plane, cylinder*/

int	validate_vector(char *str)
{
	t_val_flags	flags;
	t_val_rules	rules;

	flags = VAL_DBL | VAL_DBL_RANGE | VAL_COMPONENTS;
	rules.flags = flags;
	rules.min_dbl = -1.0;
	rules.max_dbl = 1.0;
	rules.comp = 3;
	rules.err_msg = "Normalized vector input's wrong\n";
	if (validate_value(str, rules) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
