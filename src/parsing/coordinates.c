
#include "../../include/miniRT.h"

/*coordinates [do we have any restrictions?], flt, 3 numbers
for camera, light, sphere, plane, cylinder*/

int	validate_coordinates(char *str, char *element)
{
	t_val_flags	flags;
	t_val_rules	rules;
	t_val_err	err;

	flags = VAL_FLT | VAL_COMPONENTS;
	rules.flags = flags;
	rules.comp = 3;
	err = validate_value(str, rules);
	if (err != VAL_SUCCESS)
		return (print_val_err(err, element, "Coordinates"));
	return (SUCCESS);
}

int	init_coordinates(char *three)
{

}
