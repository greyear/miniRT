
#include "../../include/miniRT.h"

static int	atod_sign(const char **str)
{
	int	sign;

	sign = 1;
	while (ft_isspace(**str))
		(*str)++;
	if (**str == '+' || **str == '-')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	return (sign);
}

static double	atod_before(const char **str)
{
	double	bef;

	bef = 0.0;
	while (ft_isdigit(**str))
	{
		bef = bef * 10.0 + (**str - '0');
		(*str)++;
	}
	return (bef);
}

static double	atod_after(const char **str)
{
	double	aft;
	double	div;

	aft = 0.0;
	div = 10.0;
	if (**str == '.')
	{
		(*str)++;
		while (ft_isdigit(**str))
		{
			aft = aft + (**str - '0') / div;
			(*str)++;
			div *= 10.0;
		}
	}
	return (aft);
}

int	rt_atod(const char *str, double *number)
{
	int		sign;
	double	bef;
	double	aft;
	double	res;

	if (!str || !number)
		return (FAILURE);
	sign = atod_sign(&str);
	bef = atod_before(&str);
	aft = atod_after(&str);
	res = (bef + aft) * sign;
	if (res > DBL_MAX || res < -DBL_MAX || isinf(res) || isnan(res))
		return (FAILURE);
	while (ft_isspace(*str))
		str++;
	if (*str != '\0')
		return (FAILURE);
	*number = res;
	return (SUCCESS);
}
