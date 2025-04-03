/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 15:40:26 by azinchen          #+#    #+#             */
/*   Updated: 2024/07/26 14:02:24 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static void	ft_posit(int num, int fd)
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
		ft_putchar_fd(symb, fd);
		i--;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n > 0)
		ft_posit(n, fd);
	if (n == 0)
		ft_putstr_fd("0", fd);
	if (n < 0)
	{
		if (n == -2147483648)
			ft_putstr_fd("-2147483648", fd);
		else
		{
			ft_putstr_fd("-", fd);
			n = -n;
			ft_posit(n, fd);
		}
	}
}
