/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:20:59 by azinchen          #+#    #+#             */
/*   Updated: 2025/04/14 14:51:09 by azinchen         ###   ########.fr       */
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

typedef enum e_obj_type
{
	SPHERE,
	CYLINDER,
	PLANE
}	t_obj_type;

typedef enum e_element_type
{
	E_AMBIENT,
	E_CAMERA,
	E_LIGHT,
	E_SPHERE,
	E_PLANE,
	E_CYLINDER,
	E_TYPES_AMOUNT
}	t_element_type;

typedef enum e_return
{
	SUCCESS = 0,
	FAILURE = 1
}	t_return;

typedef enum e_val_flags
{
	VAL_INT = 1 << 0,
	VAL_DBL = 1 << 1,
	VAL_RANGE = 1 << 2,
	VAL_COMPONENTS = 1 << 3
}	t_val_flags;

typedef struct s_val_rules
{
	t_val_flags	flags;
	double		min;
	double		max;
	int			comp;
	char		*err_msg;
}	t_val_rules;

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
	const char	*e_names[E_TYPES_AMOUNT];
	int			*e_count[E_TYPES_AMOUNT];
	int			fd;
}	t_miniRT;
