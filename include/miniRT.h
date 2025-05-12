/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:48:59 by msavelie          #+#    #+#             */
/*   Updated: 2025/04/11 15:25:08 by azinchen         ###   ########.fr       */
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
/*# include <float.h>*/

//Validation
int			validation(t_miniRT *m, int argc, char *argv[]);
int			validate_content(t_miniRT *m);
int			validate_element_type(char *line, t_miniRT *m);
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
int			allocation(t_miniRT *m);
int			init(t_miniRT *m, char *filename);
int			init_ambient(t_miniRT *m, char **args);
int			init_camera(t_miniRT *m, char **args);
int			init_light(t_miniRT *m, char **args);
int			init_sphere(t_miniRT *m, char **args);
int			init_plane(t_miniRT *m, char **args);
int			init_cylinder(t_miniRT *m, char **args);
int			init_colors(t_col *color, char *three);
int			init_coordinates(t_vector *coordinates, char *three);
int			init_vector(t_vector *vector, char *three);

//Drawing
void		draw_figure(void);
uint32_t	rgb_to_rgba(uint32_t color);
uint32_t	gradient(int fst_color, int lst_color, int steps, int cur_step);

//Cleaners
void		struct_clean(t_miniRT *rt);

//Errors
int			print_err(char *reason);
int			print_val_err(t_val_err err, char *element, char *info);

//Delete
void		print_scene_info(t_miniRT *m);

#endif