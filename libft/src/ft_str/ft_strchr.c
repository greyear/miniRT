/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:13:56 by azinchen          #+#    #+#             */
/*   Updated: 2024/07/26 14:03:08 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	symb;
	int		i;

	symb = c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == symb)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == symb)
		return ((char *)&s[i]);
	return (NULL);
}
