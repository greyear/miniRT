/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:04:47 by azinchen          #+#    #+#             */
/*   Updated: 2025/02/13 15:05:00 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strcat(char *dst, const char *src)
{
	size_t	lend;
	size_t	lens;

	if (!dst || !src)
		return (NULL);
	lend = ft_strlen(dst);
	lens = ft_strlen(src);
	ft_memcpy(dst + lend, src, lens);
	dst[lend + lens] = '\0';
	return (dst);
}
