/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:13:22 by azinchen          #+#    #+#             */
/*   Updated: 2024/07/26 14:03:56 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	lens;

	lens = ft_strlen(src);
	if (dstsize > lens + 1)
	{
		ft_memcpy(dst, src, lens);
		dst[lens] = '\0';
	}
	else
	{
		if (dstsize != 0)
		{
			ft_memcpy(dst, src, dstsize - 1);
			dst[dstsize - 1] = '\0';
		}
	}
	return (lens);
}
