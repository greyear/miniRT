/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:21:11 by azinchen          #+#    #+#             */
/*   Updated: 2024/07/26 14:03:37 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1, len1 + 1);
	ft_strlcat(res, s2, len1 + len2 + 1);
	return (res);
}
