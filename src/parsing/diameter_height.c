
#include "../../include/miniRT.h"

/*diameter/height [0.0, unlimited], 1 number
for sphere, cylinder*/

int	validate_diameter_height(char *str)
{
	t_val_flags	flags;
	t_val_rules	rules;
	t_val_err	err;

	flags = VAL_DBL | VAL_DBL_RANGE | VAL_COMPONENTS;
	rules.flags = flags;
	rules.min_dbl = 0.0;
	rules.max_dbl = DBL_MAX; //?
	rules.comp = 1;
	err = validate_value(str, rules);
	if (err != VAL_SUCCESS)
		return (print_val_err(err, "Diameter/height"));
	return (SUCCESS);
}
