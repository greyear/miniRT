/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsign.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:48:10 by azinchen          #+#    #+#             */
/*   Updated: 2024/07/26 14:08:37 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

static int	ft_digits(int fd, unsigned int num)
{
	int		dig[10];
	int		len;
	int		i;
	char	symb;

	len = 0;
	while (num > 0)
	{
		dig[len] = num % 10;
		num = num / 10;
		len++;
	}
	i = len - 1;
	while (i >= 0)
	{
		symb = dig[i] + '0';
		if (write(fd, &symb, 1) == -1)
			return (-1);
		i--;
	}
	return (len);
}

int	ft_print_unsign(int fd, unsigned int n)
{
	int	len;

	if (n == 0)
	{
		if (write(fd, "0", 1) == -1)
			return (-1);
		len = 1;
	}
	else
		len = ft_digits(fd, n);
	return (len);
}
