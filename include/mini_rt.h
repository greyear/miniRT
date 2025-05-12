/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:48:59 by msavelie          #+#    #+#             */
/*   Updated: 2025/05/12 15:20:13 by msavelie         ###   ########.fr       */
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

# include <sys/time.h> // deleteme

//Parsing
void	name_check(char *name);
void	dir_check(char *name);

//Drawing
void		draw_figure(t_rt *obj);
uint32_t	rgb_to_rgba(uint32_t color);
uint32_t	gradient(int fst_color, int lst_color, int steps, int cur_step);
void		render(t_rt *obj);
uint32_t	vec_to_rgba(t_vector color);
void		draw_pixels(t_rt *rt);
void		create_img(t_rt *rt);

//Rays
t_vector	calculate_rays(t_vector rayorig, t_vector raydir, t_rt *rt);
float		length2(t_vector vec);
float		dot(t_vector vec1, t_vector vec2);
t_vector	revert_vector(t_vector vec);
float		lerp(float a, float b, float mix);
void		clamp(t_vector *pixel);
t_vector	smooth_pixel(int x, int y, t_rt *rt);

//Intersection
bool		intersect_sphere(t_ray ray, t_obj sphere, t_hit *hit_info);
bool		intersect_cylinder(t_ray ray, t_obj cylinder, t_hit *hit_info, int *hit_part);
bool		intersect_plane(t_ray ray, t_obj plane, float *t);
bool		check_intersection(t_ray ray, t_obj object, t_hit *hit_info);
t_obj		*check_obj_intersection(t_rt *rt, t_ray ray, t_hit *hit_arr[2], float *tnear);

//Shadows
bool		check_shadow(t_rt *rt, t_obj object, t_ray light_ray, t_hit *hit_info);
t_vector	calculate_shadows(t_rt *rt, t_obj *object, t_hit *hit_info, t_ray light_ray);

//Objects
t_obj		init_obj(t_vector coordinates, t_vector em_color, t_obj_type type);
t_light		*init_light(t_rt *rt);
t_camera	*init_camera(void);
t_obj		*init_objects(t_rt *rt);

//hooks
void		keys_hook(void *obj);
void		win_resize(int width, int height, void *param);

//utils
t_vector 	vec_add(t_vector vec1, t_vector vec2);
t_vector 	vec_sub(t_vector vec1, t_vector vec2);
t_vector 	vec_mul(t_vector vec1, t_vector vec2);
t_vector 	vec_mul_num(t_vector vec1, float num);
t_vector 	vec_sub_num(t_vector vec1, float num);
float 		random_float_fast(unsigned int *seed);
void 		normalize(t_vector *vector_to_norm);
void		normilize_object(t_obj *object, t_vector *nhit, t_vector *phit, t_hit cyl_hit);

//clean
void		clean_struct(t_rt *rt);
void		clean_exit(t_rt *rt);

size_t	get_time(void); //deleteme

#endif