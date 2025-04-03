/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isemptystring.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:03:50 by azinchen          #+#    #+#             */
/*   Updated: 2025/01/20 18:22:43 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_isemptystring(char *str)
{
	int	i;

	if (str == NULL || *str == '\0')
		return (1);
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}
