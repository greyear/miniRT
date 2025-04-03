/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:55:34 by azinchen          #+#    #+#             */
/*   Updated: 2024/07/26 14:05:02 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	symb;
	int		i;

	symb = c;
	i = ft_strlen(s);
	if (symb == '\0' && s[i] == symb)
		return ((char *)&s[i]);
	while (i >= 0)
	{
		if (s[i] == symb)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}
