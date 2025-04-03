/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:03:22 by azinchen          #+#    #+#             */
/*   Updated: 2024/07/26 14:03:19 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*res;
	size_t	len;

	len = ft_strlen(s1);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res = ft_memcpy(res, s1, len);
	res[len] = '\0';
	return (res);
}
