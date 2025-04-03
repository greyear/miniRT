/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 13:02:07 by azinchen          #+#    #+#             */
/*   Updated: 2024/08/19 15:51:34 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static int	ft_clean(char **array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (-1);
}

static int	ft_count(const char *str, char c)
{
	int	i;
	int	res;

	res = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			res++;
		i++;
	}
	return (res);
}

static void	ft_elem(char *dest, const char *str, int start, char c)
{
	int	i;

	i = 0;
	while (str[start] != c && str[start] != '\0')
	{
		dest[i] = str[start];
		i++;
		start++;
	}
	dest[i] = '\0';
}

static int	ft_array(char **array, const char *str, char c)
{
	int		i;
	int		j;
	int		index;

	index = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			i++;
		else
		{
			j = 0;
			while (str[i + j] != c && str[i + j] != '\0')
				j++;
			array[index] = (char *)malloc((j + 1) * sizeof(char));
			if (!array[index])
				return (ft_clean(array, index));
			ft_elem(array[index], str, i, c);
			i = i + j;
			index++;
		}
	}
	return (0);
}

char	**ft_split(const char *str, char c)
{
	char	**res;
	int		count;

	count = ft_count(str, c);
	if (count == 0)
		return (NULL);
	res = (char **)malloc((count + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	if (ft_array(res, str, c) == -1)
		return (NULL);
	res[count] = 0;
	return (res);
}
