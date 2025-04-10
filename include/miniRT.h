/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:48:59 by msavelie          #+#    #+#             */
/*   Updated: 2025/04/09 15:13:15 by msavelie         ###   ########.fr       */
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

//Validation
int			arg_check(int argc);
int			name_check(char *name);
int			dir_check(char *name);

//Parsing
void		unify_spaces(char *str);

//Drawing
void		draw_figure(void);
uint32_t	rgb_to_rgba(uint32_t color);
uint32_t	gradient(int fst_color, int lst_color, int steps, int cur_step);

//Cleaners
void		struct_clean(t_miniRT *rt);

//Errors
int			print_err(char *reason);

#endif