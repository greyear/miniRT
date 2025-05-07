
#include "../../include/miniRT.h"

/*ratio [0.0,1.0], 1 number
for ambient, light*/

int	validate_ratio(char *str)
{
	t_val_flags	flags;
	t_val_rules	rules;

	flags = VAL_DBL | VAL_DBL_RANGE | VAL_COMPONENTS;
	rules.flags = flags;
	rules.min_dbl = 0.0;
	rules.max_dbl = 1.0;
	rules.comp = 1;
	rules.err_msg = "Ratio input's wrong\n";
	if (validate_value(str, rules) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
