/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:30:04 by azinchen          #+#    #+#             */
/*   Updated: 2024/05/10 13:30:09 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int	ft_print_str(int fd, char *str)
{
	int	len;

	if (str == NULL)
	{
		if (write(fd, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	len = 0;
	while (str[len])
		len++;
	if (write(fd, str, len) == -1)
		return (-1);
	return (len);
}
