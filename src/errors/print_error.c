/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:40:48 by azinchen          #+#    #+#             */
/*   Updated: 2025/05/13 12:40:52 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

int	print_err(char *reason)
{
	ft_putstr_fd(ERR_MSG, STDERR_FILENO);
	ft_putstr_fd(reason, STDERR_FILENO);
	return (FAILURE);
}

static char	*parsing_err(t_val_err err)
{
	if (err == VAL_ERR_EMPTY)
		return (EMPTY_MSG);
	else if (err == VAL_ERR_MINUS)
		return (MINUS_MSG);
	else if (err == VAL_ERR_NOT_DIGIT)
		return (FORBID_MSG);
	else if (err == VAL_ERR_DOTS)
		return (DOTS_MSG);
	else if (err == VAL_ERR_BEF_DOT)
		return (BEF_DOT_MSG);
	else if (err == VAL_ERR_AFT_DOT)
		return (AFT_DOT_MSG);
	else if (err == VAL_ERR_NO_DIGIT)
		return (DIGIT_MSG);
	else if (err == VAL_ERR_COMPONENTS)
		return (COMP_MSG);
	else if (err == VAL_ERR_RANGE)
		return (RANGE_MSG);
	else if (err == VAL_ERR_CONFLICTING_FLAGS)
		return (CONFL_MSG);
	else if (err == VAL_ERR_ATON)
		return (ATON_MSG);
	else if (err == VAL_ERR_MALLOC)
		return (MLLC_MSG);
	return (UNKNOWN_MSG);
}

int	print_val_err(t_val_err err, char *element, char *info)
{
	ft_putstr_fd(ERR_MSG, STDERR_FILENO);
	ft_putstr_fd(element, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(info, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(parsing_err(err), STDERR_FILENO);
	return (FAILURE);
}
