
#include "../../include/miniRT.h"

int	rt_atoi(const char *str, int *number)
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
			return (FAILURE);
	}
	while (ft_isspace(str[i]))
		i++;
	if (str[i] != '\0')
		return (FAILURE);
	*number = (int)sign * res;
	return (SUCCESS);
}
