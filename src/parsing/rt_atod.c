
#include "../../include/miniRT.h"
/*
static int	rt_atoi(const char *str, int *number)
{
	long	sign;
	int		i;
	long	res;

	i = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (ft_issign(str[i]) && str[i++] == '-')
		sign = -1;
	res = 0;
	while (ft_isdigit(str[i]))
	{
		res = res * 10 + (str[i++] - '0');
		if (res * sign < (long)INT_MIN || res * sign > (long)INT_MAX)
			return (1);
	}
	*number = (int)sign * res;
	return (0);
}
*/

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
	
}

int	rt_atod(const char *str, double *number)
{
	int		sign;
	double	bef;
	double	aft;
	double	div;
	double	res;

	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	bef = 0.0;
	while (ft_isdigit(*str))
		bef = bef * 10.0 + (*str++ - '0');
	aft = 0.0;
	div = 10.0;
	if (*str == '.')
	{
		str++;
		while (ft_isdigit(*str))
		{
			aft = aft + (*str++ - '0') / div;
			div *= 10.0;
		}
	}
	res = (bef + aft) * sign;
	if (res > DBL_MAX || res < -DBL_MAX || isinf(res) || isnan(res))
		return (1);
	while (ft_isspace(*str))
		str++;
	if (*str != '\0')
		return (1);
	*number = res;
	return (0);
}
