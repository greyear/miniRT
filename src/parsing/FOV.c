
#include "../../include/miniRT.h"

/*FOV [0-180] int, 1 number
for camera*/

int	validate_fov(char *str)
{
	t_val_flags	flags;
	t_val_rules	rules;

	flags = VAL_INT | VAL_INT_RANGE | VAL_COMPONENTS;
	rules.flags = flags;
	rules.min_int = 0;
	rules.max_int = 180;
	rules.comp = 1;
	rules.err_msg = "FOV input's wrong\n";
	if (validate_value(str, rules) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
