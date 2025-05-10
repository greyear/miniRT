/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:20:59 by azinchen          #+#    #+#             */
/*   Updated: 2025/05/05 16:48:40 by msavelie         ###   ########.fr       */
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
	double	x;
	double	y;
	double	z;
}	t_vector;

typedef struct s_obj
{
	t_obj_type	type;
	t_vector	coordinates;
	t_vector	normalized;
	double		height;
	double		diameter;
	double		radius;
	t_vector	color;
	t_vector	emission_color;
}	t_obj;

typedef struct s_ambient
{
	double	ratio;
	t_color	color;
}	t_ambient;

typedef struct s_light
{
	t_vector	coordinates;
	t_vector	color;
	t_vector	emission_color;
	double		diameter;
	double		ratio;
}	t_light;

typedef struct s_camera
{
	t_vector	coordinates;
	t_vector	normalized;
	double		fov;
	double		viewporw_size;
	double		aspect_ratio;
	double		angle;
}	t_camera;

typedef struct s_ray
{
	t_vector	origin;
	t_vector	destination;
}	t_ray;

typedef struct s_hit
{
	double		t0;
	double		t1;
	int			temp_part;
	int			hit_part;
	t_vector	phit;
	t_vector	nhit;
}	t_hit;

typedef struct s_light_calc
{
	t_ray		light_ray;
	t_vector	transmission;
	t_vector	light_contribution;
	t_vector	surface_color;
	double		light_intensity;
}	t_light_calc;

typedef struct s_cyl_inter
{
	t_vector	oc;
	double		dir_dot_axis;
	t_vector	ray_perp_dir;
	double		ray_perp_len;
	double		oc_dot_axis;
	t_vector	oc_proj;
	double		discriminant;
	double		sqrt_disc;
	double		t0;
	double		t1;
	double		t_candidate;
	t_vector	intersection;
	t_vector	to_point;
	int			*hit_part;
}	t_cyl_inter;

typedef struct s_rt
{
	int			width;
	int			height;
	t_obj		*objects;
	t_ambient	*amb_light;
	t_light		*light;
	t_camera	*camera;
	mlx_t		*mlx;
	int			obj_count;
	t_vector	ambient_light;
	t_vector	*image;
	mlx_image_t	*mlx_img;
	int			needs_render;
}	t_rt;
