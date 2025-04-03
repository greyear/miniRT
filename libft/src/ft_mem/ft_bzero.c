/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:50:18 by azinchen          #+#    #+#             */
/*   Updated: 2024/07/26 14:00:26 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*mem;
	size_t			i;

	mem = s;
	i = 0;
	while (i < n)
	{
		mem[i] = '\0';
		i++;
	}
}
