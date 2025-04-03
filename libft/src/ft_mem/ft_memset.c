/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:37:20 by azinchen          #+#    #+#             */
/*   Updated: 2024/07/26 14:01:37 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_memset(void	*b, int c, size_t len)
{
	unsigned char	*mem;
	size_t			i;
	unsigned char	symb;

	mem = b;
	symb = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		mem[i] = symb;
		i++;
	}
	return ((void *)mem);
}
