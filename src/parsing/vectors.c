
#include "../../include/miniRT.h"

/*3d normalized vector [-1.0,1.0] double, 3 numbers
for camera, plane, cylinder*/

int	validate_vector(char *str)
{
	t_val_flags	flags;
	t_val_rules	rules;
	t_val_err	err;

	flags = VAL_DBL | VAL_DBL_RANGE | VAL_COMPONENTS;
	rules.flags = flags;
	rules.min_dbl = -1.0;
	rules.max_dbl = 1.0;
	rules.comp = 3;
	err = validate_value(str, rules);
	if (err != VAL_SUCCESS)
		return (print_val_err(err, "Vector"));
	return (SUCCESS);
}
