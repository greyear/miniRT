/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:18:00 by azinchen          #+#    #+#             */
/*   Updated: 2024/07/26 14:08:14 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

static int	ft_long_hex_arr(unsigned long n, char hexa[16])
{
	int	dig;
	int	len;

	len = 0;
	while (n != 0)
	{
		dig = n % 16;
		if (dig < 10)
			dig = dig + '0';
		else
			dig = dig + 'a' - 10;
		hexa[len++] = dig;
		n = n / 16;
	}
	return (len);
}

static int	ft_print_long_hexa(int fd, unsigned long n)
{
	int		len;
	int		i;
	char	hexa[16];

	if (n == 0)
	{
		if (write(fd, "0", 1) == -1)
			return (-1);
		return (1);
	}
	len = ft_long_hex_arr(n, hexa);
	i = len - 1;
	while (i >= 0)
	{
		if (ft_print_char(fd, hexa[i--]) == -1)
			return (-1);
	}
	return (len);
}

int	ft_print_pointer(int fd, void *p)
{
	int	len;

	if (p == NULL)
	{
		if (write(fd, "(nil)", 5) == -1)
			return (-1);
		return (5);
	}
	len = 0;
	if (write(fd, "0x", 2) == -1)
		return (-1);
	else
		len += 2;
	len += ft_print_long_hexa(fd, (unsigned long)p);
	return (len);
}
