/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   content_validation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:16:04 by azinchen          #+#    #+#             */
/*   Updated: 2025/04/11 15:23:40 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

void	unify_spaces(char *str)
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

