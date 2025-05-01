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
# include <float.h>

//Validation
int			validation(t_miniRT *m, int argc, char *argv[]);
int			validate_content(t_miniRT *m);

//Parsing
int			validate_element_type(char *line, t_miniRT *m);
int			validate_ambient(char **args);
int			validate_camera(char **args);
int			validate_light(char **args);
int			validate_sphere(char **args);
int			validate_plane(char **args);
int			validate_cylinder(char **args);

//ATON
int			rt_atod(const char *str, double *number);

//Drawing
void		draw_figure(void);
uint32_t	rgb_to_rgba(uint32_t color);
uint32_t	gradient(int fst_color, int lst_color, int steps, int cur_step);

//Cleaners
void		struct_clean(t_miniRT *rt);

//Errors
int			print_err(char *reason);

#endif