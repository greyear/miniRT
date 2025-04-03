/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:29:21 by azinchen          #+#    #+#             */
/*   Updated: 2024/05/10 13:29:28 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

static int	ft_print_posit(int fd, int num)
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

static int	ft_print_neg(int fd, int num)
{
	int	len;

	len = 0;
	if (num == -2147483648)
	{
		if (write(fd, "-2147483648", 11) == -1)
			return (-1);
		else
			len = 11;
	}
	else
	{
		if (write(fd, "-", 1) == -1)
			return (-1);
		else
			len += 1;
		num = -num;
		len += ft_print_posit(fd, num);
	}
	return (len);
}

int	ft_print_int(int fd, int n)
{
	int	len;

	len = 0;
	if (n > 0)
		len = ft_print_posit(fd, n);
	if (n == 0)
	{
		if (write(fd, "0", 1) == -1)
			return (-1);
		len = 1;
	}
	if (n < 0)
		len = ft_print_neg(fd, n);
	return (len);
}
