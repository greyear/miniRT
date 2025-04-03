/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 20:07:07 by azinchen          #+#    #+#             */
/*   Updated: 2024/10/04 15:17:25 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_atoi(const char	*str)
{
	int		sign;
	int		i;
	long	res;
	long	prev;

	i = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (ft_issign(str[i]) && str[i++] == '-')
		sign = -1;
	res = 0;
	while (ft_isdigit(str[i]))
	{
		prev = res;
		res = res * 10 + (str[i++] - '0');
		if (prev != res / 10 && sign == -1)
			return (0);
		if (prev != res / 10 && sign == 1)
			return (-1);
	}
	return ((int)sign * res);
}
