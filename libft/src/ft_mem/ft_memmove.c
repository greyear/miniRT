/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:17:34 by azinchen          #+#    #+#             */
/*   Updated: 2024/07/26 14:01:28 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static void	ft_forward(unsigned char *dst, const unsigned char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
}

static void	ft_backward(unsigned char *dst, const unsigned char *src,
size_t len)
{
	size_t	i;

	i = len;
	while (i > 0)
	{
		i--;
		dst[i] = src[i];
	}
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dst1;
	const unsigned char	*src1;

	if (!dst && !src)
		return (NULL);
	dst1 = dst;
	src1 = src;
	if (dst < src)
		ft_forward(dst1, src1, len);
	else
		ft_backward(dst1, src1, len);
	return ((void *)dst1);
}
