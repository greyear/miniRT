/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:18:53 by azinchen          #+#    #+#             */
/*   Updated: 2024/11/04 16:18:55 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static int	digit_from_char(char c)
{
	int	max;

	max = 16 - 1 + 'a' - 10;
	if (ft_isdigit(c) && c <= max)
		return (c - '0');
	else if (c >= 'a' && c <= 'f' && c <= max)
		return (c - 'a' + 10);
	else
		return (-1);
}

int	ft_atoi_color(const char *str)
{
	int	res;
	int	dig;
	int	i;

	res = 0;
	i = 2;
	while (str[i])
	{
		dig = digit_from_char(ft_tolower(str[i]));
		if (dig == -1)
			break ;
		res = res * 16 + dig;
		i++;
	}
	return (res);
}
