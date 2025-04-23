/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:48:59 by msavelie          #+#    #+#             */
/*   Updated: 2025/04/14 15:27:11 by msavelie         ###   ########.fr       */
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
void		draw_figure(t_vector *image, t_miniRT *obj);
uint32_t	rgb_to_rgba(uint32_t color);
uint32_t	gradient(int fst_color, int lst_color, int steps, int cur_step);
t_vector	*render(t_miniRT *obj);
uint32_t	vec_to_rgba(t_vector color);

//Rays
float		length2(t_vector vec);
float		dot(t_vector vec1, t_vector vec2);
t_vector	revert_vector(t_vector vec);
t_vector	calculate_with_vector(t_vector vec1, t_vector vec2, t_calc operation);
t_vector	calculate_with_number(t_vector vec, float num, t_calc operation);
float		lerp(float a, float b, float mix);
float		min(float a, float b);
float		max(float a, float b);
void		clamp(t_vector *pixel);
float		random_float(void);

//Objects
t_obj		init_obj(t_vector coordinates, t_vector em_color);
void		init_light(t_light *light);

//hooks
void		keys_hook(void *obj);

//clean
void		clean_struct(t_miniRT *rt);

#endif