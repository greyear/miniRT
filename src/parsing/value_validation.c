
#include "../../include/miniRT.h"

int	int_out_of_range(char *str, int min, int max)
{
	int	value;

	if (rt_atoi(str, &value) == 1)
	{
		ft_putstr_fd(NUM_MSG, STDERR_FILENO);
		return (print_err(str));
	}
	if (value < min || value > max)
	{
		ft_putstr_fd(str, STDERR_FILENO);
		return (print_err(RANGE_MSG));
	}
	return (SUCCESS);
}

int	dbl_out_of_range(char *str, double min, double max)
{
	double	value;

	if (rt_atod(str, &value) == 1)
	{
		ft_putstr_fd(NUM_MSG, STDERR_FILENO);
		return (print_err(str));
	}
	if (value < min || value > max)
	{
		ft_putstr_fd(str, STDERR_FILENO);
		return (print_err(RANGE_MSG));
	}
	return (SUCCESS);
}

int validate_value(char *str, t_val_rules rules)
{
	char	**set;
	char	**cur;
	int		fail_flag;

	set = ft_split(str, ',');
	if (!set)
		return (print_err(MLLC_MSG));
	fail_flag = 0;
	if ((rules.flags & VAL_COMPONENTS) &&
			(ft_array_len(set) != rules.comp))
		fail_flag = 1;
	cur = set;
	while (*cur)
	{
		if (((rules.flags & VAL_INT) && (pre_atoi(*cur))) ||
				((rules.flags & VAL_DBL) && (pre_atod(*cur))) ||
				((rules.flags & VAL_INT_RANGE) &&
				(int_out_of_range(*cur, rules.min_int, rules.max_int))) ||
				((rules.flags & VAL_DBL_RANGE) &&
				(dbl_out_of_range(*cur, rules.min_dbl, rules.max_dbl))))
			fail_flag = 1;
		cur++;
	}
	ft_clean_arr(&set);
	if (fail_flag)
		return (FAILURE);
	return (SUCCESS);
}
