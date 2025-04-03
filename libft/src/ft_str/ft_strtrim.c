/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:00:09 by azinchen          #+#    #+#             */
/*   Updated: 2024/07/26 14:05:16 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static int	ft_fromset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	min;
	size_t	max;
	char	*res;

	if (!s1)
		return (NULL);
	if (s1[0] == '\0' || !set || set[0] == '\0')
		return (ft_strdup(s1));
	len = ft_strlen(s1);
	min = 0;
	while (min < len && ft_fromset(s1[min], set))
		min++;
	max = len - 1;
	while (max > min && ft_fromset(s1[max], set))
		max--;
	if (min > max)
		return (ft_strdup(""));
	res = ft_substr(s1, min, max - min + 1);
	return (res);
}
