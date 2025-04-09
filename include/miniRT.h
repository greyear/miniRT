/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:48:59 by msavelie          #+#    #+#             */
/*   Updated: 2025/04/09 14:23:38 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

//# include "../MLX42/include/MLX42/MLX42.h"
# include <stdint.h>
# include "constants.h"
# include "structs.h"
# include "../libft/include/libft.h"
# include "../libft/include/ft_printf.h"
# include "../libft/include/get_next_line.h"
# include <stdio.h>
# include <string.h> //strerror
# include <stdlib.h>

# include <fcntl.h>
# include <dirent.h> 
# include <math.h>
# include <limits.h>

//Parsing
void	name_check(char *name);
void	dir_check(char *name);

//Drawing
void	draw_figure(void);

#endif