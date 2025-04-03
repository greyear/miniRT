/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:20:15 by azinchen          #+#    #+#             */
/*   Updated: 2024/07/26 14:04:49 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	len1;
	size_t	len2;

	if (needle[0] == '\0')
		return ((char *)haystack);
	len1 = ft_strlen(haystack);
	len2 = ft_strlen(needle);
	if (len > len1)
		len = len1;
	i = 0;
	while ((haystack[i] != '\0') && (i + len2 < len + 1))
	{
		if (ft_memcmp(&haystack[i], needle, len2) == 0)
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
