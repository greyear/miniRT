/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:48:59 by msavelie          #+#    #+#             */
/*   Updated: 2025/05/20 15:03:24 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RT_H
# define MINI_RT_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/include/libft.h"
# include <stdint.h>
# include "constants.h"
# include "structs.h"
# include <stdio.h>
# include <string.h> //strerror
# include <dirent.h> 
# include <math.h>
# include <float.h>

# include <sys/time.h> // deleteme

//Validation
int			validation(t_rt *m, int argc, char *argv[]);
int			validate_content(t_rt *m);
int			validate_element_type(char *line, t_rt *m);
int			validate_ambient(char **args);
int			validate_camera(char **args);
int			validate_light(char **args);
int			validate_sphere(char **args);
int			validate_plane(char **args);
int			validate_cylinder(char **args);
t_val_err	validate_value(char *str, t_val_rules rules);
int			validate_color(char *str, char *element);
int			validate_vector(char *str, char *element);
int			validate_ratio(char *str, char *element);
int			validate_coordinates(char *str, char *element);
int			validate_fov(char *str, char *element);
int			validate_diameter_height(char *str, char *element);
t_val_err	int_out_of_range(char *str, int min, int max);
t_val_err	flt_out_of_range(char *str, float min, float max);
int			cleaning_line(char **str);

//Parsing
t_val_err	pre_atoi(char *str);
t_val_err	pre_atof(char *str);
int			rt_atoi(const char *str, int *number);
int			rt_atof(const char *str, float *number);
int			allocation(t_rt *m);
int			init(t_rt *m, char *filename);
int			init_ambient(t_rt *m, char **args);
int			init_camera(t_rt *m, char **args);
int			init_light(t_rt *m, char **args);
int			init_sphere(t_rt *m, char **args);
int			init_plane(t_rt *m, char **args);
int			init_cylinder(t_rt *m, char **args);
int			init_colors(t_col *color, char *three);
int			init_coordinates(t_vector *coordinates, char *three);
int			init_vector(t_vector *vector, char *three);

//Errors
int			print_err(char *reason);
int			print_val_err(t_val_err err, char *element, char *info);

//Delete
void		print_scene_info(t_rt *m);

//Drawing
void		draw_figure(t_rt *obj);
void		render(t_rt *obj);
uint32_t	vec_to_rgba(t_vector color);
void		draw_pixels(t_rt *rt);
void		create_img(t_rt *rt);
t_vector	rgb_to_vec(t_col color);
void		draw_gui(t_rt *rt);

//Rays
t_vector	calculate_rays(t_vector rayorig, t_vector raydir, t_rt *rt);
float		lerp(float a, float b, float mix);
void		clamp(t_vector *pixel);
float		dot_product(t_vector a, t_vector b);
t_vector	cross_product(t_vector a, t_vector b);
t_vector	smooth_pixel(int x, int y, t_rt *rt);

//Intersection
bool		intersect_sphere(t_ray ray, t_obj sphere, t_hit *hit_info);
bool		intersect_cylinder(t_ray ray, t_obj cylinder, t_hit *hit_info,
				int *hit_part);
bool		intersect_plane(t_ray ray, t_obj plane, float *t);
bool		check_intersection(t_ray ray, t_obj object, t_hit *hit_info);
t_obj		*check_obj_intersection(t_rt *rt, t_ray ray,
				t_hit *hit_arr[2], float *tnear);

//Shadows
t_vector	calculate_shadows(t_rt *rt, t_obj *object,
				t_hit *hit_info, t_ray light_ray);

//Hooks
void		main_hook(void *obj);
void		keys_hook(mlx_key_data_t keydata, void *obj);
void		win_resize(int width, int height, void *param);
void		transform(t_rt *rt, mlx_key_data_t keydata, t_vector change);
void		select_objects(t_rt *rt);
void		select_light(t_rt *rt);
void		select_camera(t_rt *rt);
void		set_move_mode(t_rt *rt);
void		set_rotate_mode(t_rt *rt);
void		set_scale_mode(t_rt *rt);
void		move(t_rt *rt, t_vector change);
void		scale(t_rt *rt, mlx_key_data_t keydata, t_vector change);
void		rotate_x(t_vector *vec, float alpha);
void		rotate_y(t_vector *vec, float beta);
void		rotate_z(t_vector *vec, float gamma);
void		rotate(t_rt *rt, mlx_key_data_t keydata, t_vector change);

//Utils
t_vector	vec_add(t_vector vec1, t_vector vec2);
t_vector	vec_sub(t_vector vec1, t_vector vec2);
t_vector	vec_mul(t_vector vec1, t_vector vec2);
t_vector	vec_mul_num(t_vector vec1, float num);
t_vector	vec_sub_num(t_vector vec1, float num);
float		random_float_fast(unsigned int *seed);
void		normalize(t_vector *vector_to_norm);
void		normilize_object(t_obj *object, t_vector *nhit,
				t_vector *phit, t_hit cyl_hit);
t_vector	normalize_return(t_vector vector_to_norm);
void		compute_quadratic_roots(t_cyl_inter *inter_obj, float b);
void		calc_discriminant(t_cyl_inter *inter_obj, t_obj cylinder);
float		calc_cap_offset(t_obj cylinder, int cap);
void		calc_hit_part(int cap, int *hit_part);
t_vector	calc_cap_center(t_obj cylinder, int cap);
void		check_caps_intersection(t_obj cylinder, t_hit *hit_info,
				t_ray ray, int *hit_part);
float		vec_length(t_vector v);
float		length2(t_vector vec);
float		dot(t_vector vec1, t_vector vec2);
t_vector	revert_vector(t_vector vec);

//Clean
void		clean_struct(t_rt *rt);
void		clean_exit(t_rt *rt);

#endif