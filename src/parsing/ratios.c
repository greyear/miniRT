
#include "../../include/miniRT.h"

/*ratio [0.0,1.0], 1 number
for ambient, light*/

int	validate_ratio(char *str)
{
	t_val_flags	flags;
	t_val_rules	rules;
	t_val_err	err;

	flags = VAL_FLT | VAL_FLT_RANGE | VAL_COMPONENTS;
	rules.flags = flags;
	rules.min_flt = 0.0;
	rules.max_flt = 1.0;
	rules.comp = 1;
	err = validate_value(str, rules);
	if (err != VAL_SUCCESS)
		return (print_val_err(err, "Ratio"));
	return (SUCCESS);
}
