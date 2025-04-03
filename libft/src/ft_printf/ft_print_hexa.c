/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:29:05 by azinchen          #+#    #+#             */
/*   Updated: 2024/07/26 14:07:47 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

static int	ft_hex_arr(unsigned int n, int flag, char hexa[16])
{
	int	dig;
	int	len;

	len = 0;
	while (n != 0)
	{
		dig = n % 16;
		if (dig < 10)
			dig = dig + '0';
		else if (flag == 1)
			dig = dig + 'A' - 10;
		else if (flag == 0)
			dig = dig + 'a' - 10;
		hexa[len++] = dig;
		n = n / 16;
	}
	return (len);
}

int	ft_print_hexa(int fd, unsigned int n, int flag)
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
	len = ft_hex_arr(n, flag, hexa);
	i = len - 1;
	while (i >= 0)
	{
		if (ft_print_char(fd, hexa[i--]) == -1)
			return (-1);
	}
	return (len);
}
