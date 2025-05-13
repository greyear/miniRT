/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   content_validation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:16:04 by azinchen          #+#    #+#             */
/*   Updated: 2025/04/14 16:11:49 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

static void	unify_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isspace(str[i]))
			str[i] = ' ';
		i++;
	}
}

int	cleaning_line(char **str)
{
	char	*trimmed;

	trimmed = ft_strtrim(*str, " \t\n\r\f\v");
	free(*str);
	*str = trimmed;
	if (!trimmed || trimmed[0] == '\0')
		return (FAILURE);
	unify_spaces(*str);
	return (SUCCESS);
}

static int	at_least_one_element(t_miniRT *m)
{
	int	i;

	i = 0;
	while (i < E_TYPES_AMOUNT)
	{
		if (m->e_count[i])
			return (SUCCESS);
		i++;
	}
	return (FAILURE);
}

int	validate_content(t_miniRT *m)
{
	char	*line;

	line = get_next_line(m->fd);
	while (line)
	{
		if (cleaning_line(&line))
		{
			free(line);
			line = get_next_line(m->fd);
			continue ;
		}
		if (validate_element_type(line, m) == FAILURE)
		{
			free(line);
			ft_clean_gnl(m->fd);
			return (FAILURE);
		}
		free(line);
		line = get_next_line(m->fd);
	}
	if (at_least_one_element(m) == FAILURE)
		return (print_err(NO_ELEM_MSG));
	ft_printf(2, "validated\n"); //delete
	return (SUCCESS);
}
