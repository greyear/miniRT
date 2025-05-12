
#include "../../include/miniRT.h"

t_val_err	pre_atoi(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (VAL_ERR_EMPTY);
	if (str[0] == '-')
		i++;
	if (!str[i])
		return (VAL_ERR_MINUS);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (VAL_ERR_NOT_DIGIT);
		i++;
	}
	return (VAL_SUCCESS);
}

static t_val_err	start_line(char *str, int *i)
{
	if (!str || !str[0])
		return (VAL_ERR_EMPTY);
	if (str[0] == '-')
		(*i)++;
	if (!str[*i])
		return (VAL_ERR_MINUS);
	return (VAL_SUCCESS);
}

static t_val_err	handle_dot(char *str, int i, int *met_dot)
{
	if (*met_dot)
		return (VAL_ERR_DOTS);
	if (i == 0 || !ft_isdigit(str[i - 1]))
		return (VAL_ERR_BEF_DOT);
	if (!str[i + 1])
		return (VAL_ERR_AFT_DOT);
	*met_dot = 1;
	return (VAL_SUCCESS);
}

static t_val_err	process_line(char *str, int *i)
{
	int			met_dot;
	int			met_digit;
	t_val_err	err;

	met_dot = 0;
	met_digit = 0;
	while (str[*i])
	{
		if (str[*i] == '.')
		{
			err = handle_dot(str, *i, &met_dot);
			if (err != VAL_SUCCESS)
				return (err);
		}
		else if (ft_isdigit(str[*i]))
			met_digit = 1;
		else
			return (VAL_ERR_NOT_DIGIT);
		(*i)++;
	}
	if (!met_digit)
		return (VAL_ERR_NO_DIGIT);
	return (VAL_SUCCESS);
}

t_val_err	pre_atof(char *str)
{
	int			i;
	t_val_err	err;

	i = 0;
	err = start_line(str, &i);
	if (err != VAL_SUCCESS)
		return (err);
	err = process_line(str, &i);
	if (err != VAL_SUCCESS)
		return (err);
	return (VAL_SUCCESS);
}
