/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:07:42 by azinchen          #+#    #+#             */
/*   Updated: 2024/07/26 14:03:47 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	lend;
	size_t	lens;

	lend = ft_strlen(dst);
	lens = ft_strlen(src);
	if (dstsize > (lend + lens))
	{
		ft_memcpy(dst + lend, src, lens);
		dst[lend + lens] = '\0';
	}
	else
	{
		if (dstsize != 0 && dstsize > lend)
		{
			ft_memcpy(dst + lend, src, dstsize - lend - 1);
			dst[dstsize - 1] = '\0';
		}
		else
			return (dstsize + lens);
	}
	return (lend + lens);
}
