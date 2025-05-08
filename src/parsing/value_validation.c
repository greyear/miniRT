
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

t_val_err	dbl_out_of_range(char *str, double min, double max)
{
	double	value;

	if (rt_atod(str, &value) == 1)
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
	if ((rules.flags & VAL_INT) && (rules.flags & VAL_DBL))
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
		if ((rules.flags & VAL_DBL) && ((err = pre_atod(*cur)) != VAL_SUCCESS))
			break ;
		if ((rules.flags & VAL_INT_RANGE) &&
				((err = int_out_of_range(*cur, rules.min_int, rules.max_int)) != VAL_SUCCESS))
			break ;
		if ((rules.flags & VAL_DBL_RANGE) &&
				((err = dbl_out_of_range(*cur, rules.min_dbl, rules.max_dbl)) != VAL_SUCCESS))
			break ;
		cur++;
	}
	ft_clean_arr(&set);
	return (err);
}
