/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:18:06 by azinchen          #+#    #+#             */
/*   Updated: 2024/11/04 16:18:08 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_UTILS_H
# define GET_NEXT_LINE_UTILS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

size_t	ft_strln(const char *str);
char	*ft_strchar(const char *s, int c);
char	*ft_strjoin_stash(char *stash, char *buf);
char	*ft_substrg(char *stash, unsigned int start, size_t len);
size_t	find_nl(char *stash);

#endif
