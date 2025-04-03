/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:51:12 by azinchen          #+#    #+#             */
/*   Updated: 2024/05/10 13:51:17 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(int fd, const char *str, ...);
int	ft_print_char(int fd, char c);
int	ft_print_str(int fd, char *str);
int	ft_print_int(int fd, int n);
int	ft_print_unsign(int fd, unsigned int n);
int	ft_print_hexa(int fd, unsigned int n, int flag);
int	ft_print_pointer(int fd, void *n);

#endif
