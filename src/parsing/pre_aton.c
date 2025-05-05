
#include "../../include/miniRT.h"

int	pre_atoi(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (print_err(EMPTY_MSG));
	if (str[0] == '-')
		i++;
	if (!str[i])
		return (print_err(MINUS_MSG));
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (print_err(FORBID_MSG));
		i++;
	}
	return (SUCCESS);
}
static int	start_line(char *str, int *i)
{
	if (!str || !str[0])
		return (print_err(EMPTY_MSG));
	if (str[0] == '-')
		(*i)++;
	if (!str[*i])
		return (print_err(MINUS_MSG));
	return (SUCCESS);
}

static int	handle_dot(char *str, int i, int *met_dot)
{
	if (*met_dot)
		return (print_err(DOTS_MSG));
	if (i == 0 || !ft_isdigit(str[i - 1]))
		return (print_err(BEF_DOT_MSG));
	if (!str[i + 1])
		return (print_err(AFT_DOT_MSG));
	*met_dot = 1;
	return (SUCCESS);
}

static int	process_line(char *str, int *i)
{
	int	met_dot;
	int	met_digit;

	met_dot = 0;
	met_digit = 0;
	while (str[*i])
	{
		if (str[*i] == '.')
		{
			if (handle_dot(str, *i, &met_dot))
				return (FAILURE);
		}
		else if (ft_isdigit(str[*i]))
			met_digit = 1;
		else
			return (print_err(FORBID_MSG));
		(*i)++;
	}
	if (!met_digit)
		return (print_err(DIGIT_MSG));
	return (SUCCESS);
}

int	pre_atod(char *str)
{
	int	i;

	i = 0;
	if (start_line(str, &i))
		return (FAILURE);
	if (process_line(str, &i))
		return (FAILURE);
	return (SUCCESS);
}
