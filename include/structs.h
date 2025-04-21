/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:20:59 by azinchen          #+#    #+#             */
/*   Updated: 2025/04/14 15:18:45 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_color
{
	uint32_t	start_col; //values from 0 to 4,294,967,295
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
	PLANE,
	LIGHT
}	t_obj_type;

typedef struct s_vector
{
	float	x;
	float	y;
	float	z;
}	t_vector;

typedef struct s_obj
{
	t_obj_type	type;
	t_vector	coordinates;
	t_vector	normalized;
	float		width;
	float		height;
	float		diameter;
	t_vector	color;
	t_vector	emission_color;
}	t_obj;

typedef struct s_ambient
{
	float	ratio;
	t_color	color;
}	t_ambient;

typedef struct s_light
{
	t_vector	coordinates;
	t_vector	color;
	t_vector	emission_color;
	float		diameter;
	float		ratio;
}	t_light;

typedef struct s_camera
{
	t_vector	coordinates;
	t_vector	normalized;
	float		view_field;
	float		viewporw_size;
}	t_camera;

typedef struct s_ray
{
	t_vector	origin;
	t_vector	destination;
}	t_ray;

typedef struct s_miniRT
{
	t_obj		*objects;
	t_ambient	*amb_light;
	t_light		*light;
	t_camera	*camera;
	mlx_t		*mlx;
	int			obj_count;
}	t_miniRT;

typedef enum s_calc
{
	ADD,
	SUBTRACT,
	MULTIPLY,
	DIVIDE
}	t_calc;
