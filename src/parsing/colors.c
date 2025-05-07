
#include "../../include/miniRT.h"

/*colors [0-255] RGB int, 3 numbers
for ambient, sphere, plane, cylinder*/

int	validate_color(char *str)
{
	t_val_flags	flags;
	t_val_rules	rules;

	flags = VAL_INT | VAL_INT_RANGE | VAL_COMPONENTS;
	rules.flags = flags;
	rules.min_int = 0;
	rules.max_int = 255;
	rules.comp = 3;
	rules.err_msg = "RGB color input's wrong\n";
	if (validate_value(str, rules) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
