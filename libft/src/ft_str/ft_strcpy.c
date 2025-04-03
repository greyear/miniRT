/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:05:21 by azinchen          #+#    #+#             */
/*   Updated: 2025/02/13 15:05:29 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	lens;

	if (!dst || !src)
		return (NULL);
	lens = ft_strlen(src);
	ft_memcpy(dst, src, lens);
	dst[lens] = '\0';
	return (dst);
}
