/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:48:59 by msavelie          #+#    #+#             */
/*   Updated: 2025/04/09 15:13:15 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/include/libft.h"
# include <fcntl.h>
# include <math.h>

# ifndef WIN_WIDTH
#  define WIN_WIDTH 2000
# endif

# ifndef WIN_HEIGHT
#  define WIN_HEIGHT 1000
# endif

# ifndef HEX_LEN
#  define HEX_LEN 8
# endif

/*--------------------STRUCTS--------------------*/

typedef struct s_color
{
	uint32_t	start_col;
	uint32_t	end_col;
	uint8_t		a_start;
	uint8_t		r_start;
	uint8_t		g_start;
	uint8_t		b_start;
	uint8_t		a_end;
	uint8_t		r_end;
	uint8_t		g_end;
	uint8_t		b_end;
	uint32_t	cur_color;
}	t_color;

typedef enum e_obj_type {
	SPHERE,
	CYLINDER,
	PLANE
}	t_obj_type;

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}	t_vector;


typedef struct s_obj
{
	t_obj_type	type;
	t_vector	coordinates;
	t_vector	normalized;
	double		width;
	double		height;
	double		diameter;
	t_color		color;
}	t_obj;

typedef struct s_ambient
{
	double	ratio;
	t_color	color;
}	t_ambient;

typedef struct s_light
{
	t_vector	coordinates;
	double		ratio;
	t_color		color;
}	t_light;

typedef struct s_camera
{
	t_vector	coordinates;
	t_vector	normalized;
	double		view_field;
}	t_camera;


typedef struct s_miniRT
{
	t_obj		*objects;
	t_ambient	amb_light;
	t_light		light;
	t_camera	camera;
}	t_miniRT;


/*--------------------FUNCTIONS--------------------*/

void		draw_figure(void);
uint32_t	rgb_to_rgba(uint32_t color);
uint32_t	gradient(int fst_color, int lst_color, int steps, int cur_step);

#endif