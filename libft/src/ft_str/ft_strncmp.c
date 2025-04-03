/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 13:15:37 by azinchen          #+#    #+#             */
/*   Updated: 2024/07/26 14:04:28 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	a;
	unsigned char	b;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && (i < n))
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
