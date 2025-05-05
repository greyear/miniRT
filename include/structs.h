/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:20:59 by azinchen          #+#    #+#             */
/*   Updated: 2025/05/05 13:24:16 by msavelie         ###   ########.fr       */
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
	float		height;
	float		diameter;
	float		radius;
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
	float		fov;
	float		viewporw_size;
	float		aspect_ratio;
	float		angle;
}	t_camera;

typedef struct s_ray
{
	t_vector	origin;
	t_vector	destination;
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
	t_vector	light_contribution;
	t_vector	surface_color;
	float		light_intensity;
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
	t_obj		*objects;
	t_ambient	*amb_light;
	t_light		*light;
	t_camera	*camera;
	mlx_t		*mlx;
	int			obj_count;
	t_vector	ambient_light;
}	t_rt;
