/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:51:52 by azinchen          #+#    #+#             */
/*   Updated: 2025/02/03 17:51:55 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	a;
	unsigned char	b;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		a = (unsigned char)s1[i];
		b = (unsigned char)s2[i];
		if (a > b)
			return (1);
		if (a < b)
			return (-1);
		i++;
	}
	return (0);
}
