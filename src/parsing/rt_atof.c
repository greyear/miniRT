
#include "../../include/miniRT.h"

static int	atof_sign(const char **str)
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

static float	atof_before(const char **str)
{
	float	bef;

	bef = 0.0;
	while (ft_isdigit(**str))
	{
		bef = bef * 10.0 + (**str - '0');
		(*str)++;
	}
	return (bef);
}

static float	atof_after(const char **str)
{
	float	aft;
	float	div;

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

int	rt_atof(const char *str, float *number)
{
	int		sign;
	float	bef;
	float	aft;
	float	res;

	if (!str || !number)
		return (FAILURE);
	sign = atof_sign(&str);
	bef = atof_before(&str);
	aft = atof_after(&str);
	res = (bef + aft) * sign;
	if (res > FLT_MAX || res < -FLT_MAX || isinf(res) || isnan(res))
		return (FAILURE);
	while (ft_isspace(*str))
		str++;
	if (*str != '\0')
		return (FAILURE);
	*number = res;
	return (SUCCESS);
}
