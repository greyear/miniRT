
#include "../../include/miniRT.h"

int print_err(char *reason)
{
	ft_putstr_fd(ERR_MSG, STDERR_FILENO);
	ft_putstr_fd(reason, STDERR_FILENO);
	return(FAILURE);
}

int	print_val_err(t_val_err err, const char *place)
{
	if (place)
		ft_putstr_fd(place, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);

	if (err == VAL_ERR_EMPTY)
		ft_putstr_fd(EMPTY_MSG, STDERR_FILENO);
	else if (err == VAL_ERR_MINUS)
		ft_putstr_fd(MINUS_MSG, STDERR_FILENO);
	else if (err == VAL_ERR_NOT_DIGIT)
		ft_putstr_fd(FORBID_MSG, STDERR_FILENO);
	else if (err == VAL_ERR_DOTS)
		ft_putstr_fd(DOTS_MSG, STDERR_FILENO);
	else if (err == VAL_ERR_BEF_DOT)
		ft_putstr_fd(BEF_DOT_MSG, STDERR_FILENO);
	else if (err == VAL_ERR_AFT_DOT)
		ft_putstr_fd(AFT_DOT_MSG, STDERR_FILENO);
	else if (err == VAL_ERR_NO_DIGIT)
		ft_putstr_fd(DIGIT_MSG, STDERR_FILENO);
	else if (err == VAL_ERR_COMPONENTS)
		ft_putstr_fd(COMP_MSG, STDERR_FILENO);
	else if (err == VAL_ERR_RANGE)
		ft_putstr_fd("value is out of allowed range\n", STDERR_FILENO);
	else if (err == VAL_ERR_CONFLICTING_FLAGS)
		ft_putstr_fd(CONFL_MSG, STDERR_FILENO);
	else if (err == VAL_ERR_PARSE)
		ft_putstr_fd("parse failed (atod/atoi)\n", STDERR_FILENO);
	else if (err == VAL_ERR_MALLOC)
		ft_putstr_fd(MLLC_MSG, STDERR_FILENO);
	return (FAILURE);
}
