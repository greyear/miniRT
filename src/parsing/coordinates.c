
#include "../../include/miniRT.h"

/*coordinates [do we have any restrictions?], dbl, 3 numbers
for camera, light, sphere, plane, cylinder*/

int	validate_coordinates(char *str)
{
	t_val_flags	flags;
	t_val_rules	rules;

	flags = VAL_DBL | VAL_COMPONENTS;
	rules.flags = flags;
	rules.comp = 3;
	rules.err_msg = "Coordinates're wrong\n";
	if (validate_value(str, rules) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
