/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 15:30:24 by azinchen          #+#    #+#             */
/*   Updated: 2024/07/26 14:02:10 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_putendl_fd(char *s, int fd)
{
	if (!s)
	{
		if (write(fd, "(null)", 6) == -1)
			return (-1);
	}
	else
	{
		if (write(fd, s, ft_strlen(s)) == -1)
			return (-1);
	}
	if (write(fd, "\n", 1) == -1)
		return (-1);
	return (0);
}
