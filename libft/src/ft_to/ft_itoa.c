/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 13:02:23 by azinchen          #+#    #+#             */
/*   Updated: 2024/07/26 14:06:06 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static int	ft_numlen(int n)
{
	int	res;

	res = 0;
	if (n <= 0)
		res++;
	while (n != 0)
	{
		n = n / 10;
		res++;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	int			len;
	char		*res;

	len = ft_numlen(n);
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	if (n == 0)
		res[0] = '0';
	if (n < 0)
		res[0] = '-';
	res[len] = '\0';
	while (n != 0)
	{
		if (n > 0)
			res[--len] = '0' + n % 10;
		else
			res[--len] = '0' - n % 10;
		n = n / 10;
	}
	return (res);
}
