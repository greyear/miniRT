/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 15:56:56 by azinchen          #+#    #+#             */
/*   Updated: 2024/07/26 14:00:54 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*s1;
	unsigned char		symb;
	size_t				i;

	s1 = (const unsigned char *)s;
	symb = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (s1[i] == symb)
			return ((void *)&s1[i]);
		i++;
	}
	return (NULL);
}
