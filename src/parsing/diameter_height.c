
#include "../../include/miniRT.h"

/*diameter/height [0.0, unlimited], 1 number
for sphere, cylinder*/

int	validate_diameter_height(char *str)
{
	t_val_flags	flags;
	t_val_rules	rules;

	flags = VAL_DBL | VAL_DBL_RANGE | VAL_COMPONENTS;
	rules.flags = flags;
	rules.min_dbl = 0.0;
	rules.max_dbl = DBL_MAX; //?
	rules.comp = 1;
	rules.err_msg = "Diameter/height's wrong\n";
	if (validate_value(str, rules) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
