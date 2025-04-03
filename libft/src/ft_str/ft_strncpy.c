/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:06:02 by azinchen          #+#    #+#             */
/*   Updated: 2025/02/13 15:06:05 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (i < dstsize && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	while (i < dstsize)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
