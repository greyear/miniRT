/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:48:59 by msavelie          #+#    #+#             */
/*   Updated: 2025/05/01 10:52:56 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RT_H
# define MINI_RT_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/include/libft.h"
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
void		draw_figure(t_vector *image, t_rt *obj);
uint32_t	rgb_to_rgba(uint32_t color);
uint32_t	gradient(int fst_color, int lst_color, int steps, int cur_step);
t_vector	*render(t_rt *obj);
uint32_t	vec_to_rgba(t_vector color);

//Rays
float		length2(t_vector vec);
float		dot(t_vector vec1, t_vector vec2);
t_vector	revert_vector(t_vector vec);
float		lerp(float a, float b, float mix);
void		clamp(t_vector *pixel);
void 		normalize(t_vector *vector_to_norm);

bool		intersect_sphere(t_ray ray, t_obj sphere, t_hit *hit_info);
bool		intersect_cylinder(t_ray ray, t_obj cylinder, t_hit *hit_info);
bool		intersect_plane(t_ray ray, t_obj plane, float *t);
bool		check_intersection(t_ray ray, t_obj object, t_hit *hit_info);

//Objects
t_obj		init_obj(t_vector coordinates, t_vector em_color, t_obj_type type);
void		init_light(t_light *light);

//hooks
void		keys_hook(void *obj);

//utils
t_vector 	vec_add(t_vector vec1, t_vector vec2);
t_vector 	vec_sub(t_vector vec1, t_vector vec2);
t_vector 	vec_mul(t_vector vec1, t_vector vec2);
t_vector 	vec_mul_num(t_vector vec1, float num);
t_vector 	vec_sub_num(t_vector vec1, float num);
float 		random_float_fast(unsigned int *seed);

//clean
void		clean_struct(t_rt *rt);

#endif