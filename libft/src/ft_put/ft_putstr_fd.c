/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 15:15:36 by azinchen          #+#    #+#             */
/*   Updated: 2024/07/26 14:02:36 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	if (!s)
	{
		if (write(fd, "(null)", 6) == -1)
			return (-1);
		return (0);
	}
	if (write(fd, s, ft_strlen(s)) == -1)
		return (-1);
	return (0);
}
