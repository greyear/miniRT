/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:20:59 by azinchen          #+#    #+#             */
/*   Updated: 2025/05/18 15:53:02 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_col
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
}	t_col;

typedef enum e_obj_type
{
	SPHERE,
	CYLINDER,
	PLANE,
	LIGHT
}	t_obj_type;

typedef enum e_mode
{
	MOVE,
	ROTATE,
	SCALE
}	t_mode;

typedef enum e_obj_sel
{
	OBJ_SEL,
	LIGHT_SEL,
	CAMERA_SEL
}	t_obj_sel;

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
	VAL_FLT = 1 << 1,
	VAL_INT_RANGE = 1 << 2,
	VAL_FLT_RANGE = 1 << 3,
	VAL_COMPONENTS = 1 << 4
}	t_val_flags;

typedef enum e_val_err
{
	VAL_SUCCESS = 0,
	VAL_ERR_EMPTY,
	VAL_ERR_MINUS,
	VAL_ERR_NOT_DIGIT,
	VAL_ERR_DOTS,
	VAL_ERR_BEF_DOT,
	VAL_ERR_AFT_DOT,
	VAL_ERR_NO_DIGIT,
	VAL_ERR_ATON,
	VAL_ERR_RANGE,
	VAL_ERR_COMPONENTS,
	VAL_ERR_CONFLICTING_FLAGS,
	VAL_ERR_MALLOC
}	t_val_err;

typedef struct s_val_rules
{
	t_val_flags	flags;
	float		min_flt;
	float		max_flt;
	int			min_int;
	int			max_int;
	int			comp;
	char		*err_msg;
}	t_val_rules;

typedef struct s_vector
{
	float	x;
	float	y;
	float	z;
}	t_vector;

typedef struct s_obj
{
	t_obj_type	type;
	t_vector	coords;
	t_vector	normalized;
	float		height;
	float		diameter;
	float		radius;
	t_col		color;
	t_vector	vec_col;
	t_vector	em_color;
}	t_obj;

typedef struct s_ambient
{
	float		ratio;
	t_col		color;
	t_vector	vec_col;
}	t_ambient;

typedef struct s_light
{
	t_vector	coords;
	t_col		color;
	t_vector	vec_col;
	t_vector	em_color;
	float		diameter;
	float		ratio;
}	t_light;

typedef struct s_camera
{
	t_vector	coords;
	t_vector	normalized;
	int			fov;
	float		aspect_ratio;
	float		angle;
}	t_camera;

typedef struct s_ray
{
	t_vector	orig;
	t_vector	dest; // rename to dir
}	t_ray;

typedef struct s_hit
{
	float		t0;
	float		t1;
	int			temp_part;
	int			hit_part;
	t_vector	phit;
	t_vector	nhit;
}	t_hit;

typedef struct s_light_calc
{
	t_ray		light_ray;
	t_vector	transmission;
	t_vector	light_contrib;
	t_vector	surf_color;
	float		light_intens;
}	t_light_calc;

typedef struct s_cyl_inter
{
	t_vector	oc;
	float		dir_dot_axis;
	t_vector	ray_perp_dir;
	float		ray_perp_len;
	float		oc_dot_axis;
	t_vector	oc_proj;
	float		discriminant;
	float		sqrt_disc;
	float		t0;
	float		t1;
	float		t_candidate;
	t_vector	intersection;
	t_vector	to_point;
	int			*hit_part;
}	t_cyl_inter;

typedef struct s_rt
{
	int			width;
	int			height;
	t_obj		*objects;
	t_ambient	amb_light;
	t_light		light;
	t_camera	camera;
	mlx_t		*mlx;
	int			obj_count;
	t_vector	*image;
	mlx_image_t	*mlx_img;
	mlx_image_t	*instr_img;
	mlx_image_t	*mode_img;
	mlx_image_t	*gui_img;
	int			needs_render;
	const char	*e_names[E_TYPES_AMOUNT];
	int			e_count[E_TYPES_AMOUNT];
	int			e_index[E_TYPES_AMOUNT];
	int			fd;
	int			cur_index;
	t_obj_sel	obj_sel;
	t_mode		mode;
	int			obj_index;
}	t_rt;

#endif