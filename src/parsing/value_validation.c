/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:48:37 by azinchen          #+#    #+#             */
/*   Updated: 2025/05/13 12:48:39 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

static t_val_err	validate_type(char *value, t_val_rules rules)
{
	t_val_err	err;

	if (rules.flags & VAL_INT)
	{
		err = pre_atoi(value);
		if (err != VAL_SUCCESS)
			return (err);
	}
	if (rules.flags & VAL_FLT)
	{
		err = pre_atof(value);
		if (err != VAL_SUCCESS)
			return (err);
	}
	return (VAL_SUCCESS);
}

static t_val_err	validate_range(char *value, t_val_rules rules)
{
	t_val_err	err;

	if (rules.flags & VAL_INT_RANGE)
	{
		err = int_out_of_range(value, rules.min_int, rules.max_int);
		if (err != VAL_SUCCESS)
			return (err);
	}
	if (rules.flags & VAL_FLT_RANGE)
	{
		err = flt_out_of_range(value, rules.min_flt, rules.max_flt);
		if (err != VAL_SUCCESS)
			return (err);
	}
	return (VAL_SUCCESS);
}

static t_val_err	validate_single(char *value, t_val_rules rules)
{
	t_val_err	err;

	err = validate_type(value, rules);
	if (err != VAL_SUCCESS)
		return (err);
	err = validate_range(value, rules);
	if (err != VAL_SUCCESS)
		return (err);
	return (VAL_SUCCESS);
}

static t_val_err	validate_set_and_rules(char **set, t_val_rules rules)
{
	if ((rules.flags & VAL_COMPONENTS) && (ft_array_len(set) != rules.comp))
		return (VAL_ERR_COMPONENTS);
	if ((rules.flags & VAL_INT) && (rules.flags & VAL_FLT))
		return (VAL_ERR_CONFLICTING_FLAGS);
	return (VAL_SUCCESS);
}

t_val_err	validate_value(char *str, t_val_rules rules)
{
	char		**set;
	char		**cur;
	t_val_err	err;

	set = ft_split(str, ',');
	if (!set)
		return (VAL_ERR_MALLOC);
	err = validate_set_and_rules(set, rules);
	if (err != VAL_SUCCESS)
	{
		ft_clean_arr(&set);
		return (err);
	}
	cur = set;
	while (*cur)
	{
		err = validate_single(*cur, rules);
		if (err != VAL_SUCCESS)
			break ;
		cur++;
	}
	ft_clean_arr(&set);
	return (err);
}
