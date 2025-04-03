/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:33:02 by azinchen          #+#    #+#             */
/*   Updated: 2024/07/26 14:01:08 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*s11;
	const unsigned char	*s21;
	unsigned char		a;
	unsigned char		b;

	s11 = s1;
	s21 = s2;
	i = 0;
	while (i < n)
	{
		a = (unsigned char)s11[i];
		b = (unsigned char)s21[i];
		if (a != b)
			return (a - b);
		i++;
	}
	return (0);
}
