/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:15:21 by azinchen          #+#    #+#             */
/*   Updated: 2025/04/09 13:06:41 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libft/include/libft.h"
# include "../libft/include/ft_printf.h"
# include "../libft/include/get_next_line.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <string.h> //strerror
# include <stdlib.h>
# include <math.h>
# include <limits.h>

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	a;
}	t_color;

/*
I have ones in libft:
	#include <fcntl.h>
	#include <unistd.h>
*/

void	name_check(char *name);


#endif
