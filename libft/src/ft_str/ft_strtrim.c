/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:00:09 by azinchen          #+#    #+#             */
/*   Updated: 2025/04/11 14:56:50 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * @brief Checks if a character is present in a given set of characters.
 * 
 * This function iterates through the `set` string to determine whether 
 * the character `c` exists within it. It returns 1 if the character is found, 
 * and 0 otherwise. This is commonly used to check for membership in a set of 
 * delimiters, whitespace characters, or other custom-defined groups.
 * 
 * @param c    The character to search for in the set.
 * @param set  A null-terminated string containing characters to check against.
 * 
 * @return Returns 1 if the character is found in the set, 0 otherwise.
 */
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

/**
 * @brief Trims characters from the beginning and end of a string.
 * 
 * This function removes all leading and trailing characters from the input 
 * string `s1` that are present in the `set` string. It does not modify the 
 * original string but returns a newly allocated string with the trimmed result.
 * 
 * If the input string contains only characters from the set, an empty string 
 * is returned. If `set` is `NULL` or empty, a duplicate of `s1` is returned.
 * 
 * @param s1   The input string to be trimmed.
 * @param set  A string containing the set of characters to trim from both ends.
 * 
 * @return A newly allocated trimmed string, or NULL if memory allocation fails.
 */
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
