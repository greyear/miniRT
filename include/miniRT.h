/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:48:59 by msavelie          #+#    #+#             */
/*   Updated: 2025/04/14 14:27:15 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/include/libft.h"
# include <stdint.h>
# include "constants.h"
# include "structs.h"
# include <stdio.h>
# include <string.h> //strerror
# include <dirent.h> 
# include <math.h>

//Parsing
void	name_check(char *name);
void	dir_check(char *name);

//Drawing
void		draw_figure(t_vector *image);
uint32_t	rgb_to_rgba(uint32_t color);
uint32_t	gradient(int fst_color, int lst_color, int steps, int cur_step);
t_vector	*render(void);
uint32_t	vec_to_rgb(t_vector color);

//Rays
double		length2(t_vector vec);
double		dot(t_vector vec1, t_vector vec2);
t_vector	revert_vector(t_vector vec);
t_vector	calculate_with_vector(t_vector vec1, t_vector vec2, t_calc operation);
t_vector	calculate_with_number(t_vector vec, double num, t_calc operation);
double		mix(double a, double b, double mix);
double		min(double a, double b);
double		max(double a, double b);

#endif