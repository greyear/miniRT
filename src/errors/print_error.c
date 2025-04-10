
#include "../../include/miniRT.h"

int print_err(char *reason)
{
	ft_putstr_fd(ERR_MSG, STDERR_FILENO);
	ft_putstr_fd(reason, STDERR_FILENO);
	return(FAILURE);
}