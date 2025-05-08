
#include "../../include/miniRT.h"

t_val_err	int_out_of_range(char *str, int min, int max)
{
	int	value;

	if (rt_atoi(str, &value) == 1)
		return (VAL_ERR_ATON);
	if (value < min || value > max)
		return (VAL_ERR_RANGE);
	return (VAL_SUCCESS);
}

t_val_err	flt_out_of_range(char *str, float min, float max)
{
	float	value;

	if (rt_atof(str, &value) == 1)
		return (VAL_ERR_ATON);
	if (value < min || value > max)
		return (VAL_ERR_RANGE);
	return (VAL_SUCCESS);
}

t_val_err	validate_value(char *str, t_val_rules rules)
{
	char		**set;
	char		**cur;
	t_val_err	err;

	set = ft_split(str, ',');
	if (!set)
		return (VAL_ERR_MALLOC);
	if ((rules.flags & VAL_COMPONENTS) &&
			(ft_array_len(set) != rules.comp))
	{
		ft_clean_arr(&set);
		return (VAL_ERR_COMPONENTS);
	}
	if ((rules.flags & VAL_INT) && (rules.flags & VAL_FLT))
	{
		ft_clean_arr(&set);
		return (VAL_ERR_CONFLICTING_FLAGS);
	}
	err = VAL_SUCCESS;
	cur = set;
	while (*cur)
	{
		if ((rules.flags & VAL_INT) && ((err = pre_atoi(*cur)) != VAL_SUCCESS))
			break ;
		if ((rules.flags & VAL_FLT) && ((err = pre_atof(*cur)) != VAL_SUCCESS))
			break ;
		if ((rules.flags & VAL_INT_RANGE) &&
				((err = int_out_of_range(*cur, rules.min_int, rules.max_int)) != VAL_SUCCESS))
			break ;
		if ((rules.flags & VAL_FLT_RANGE) &&
				((err = flt_out_of_range(*cur, rules.min_flt, rules.max_flt)) != VAL_SUCCESS))
			break ;
		cur++;
	}
	ft_clean_arr(&set);
	return (err);
}
