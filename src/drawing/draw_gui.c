/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_gui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 12:19:49 by msavelie          #+#    #+#             */
/*   Updated: 2025/05/24 12:44:53 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

static void	draw_back(mlx_image_t *image)
{
	uint32_t	x;
	uint32_t	y;

	y = 0;
	while (y < 50)
	{
		x = 0;
		while (x < 130)
		{
			mlx_put_pixel(image, x, y, 0x000000FF);
			x++;
		}
		y++;
	}
}

static char	*check_obj_type(t_rt *rt)
{
	char	*full_str;
	char	*cur_index;

	full_str = NULL;
	cur_index = ft_itoa(rt->obj_index + 1);
	if (!cur_index)
		clean_exit(rt);
	if (rt->objects[rt->obj_index].type == SPHERE)
		full_str = ft_strjoin("sphere: ", cur_index);
	else if (rt->objects[rt->obj_index].type == CYLINDER)
		full_str = ft_strjoin("cylinder: ", cur_index);
	else if (rt->objects[rt->obj_index].type == PLANE)
		full_str = ft_strjoin("plane: ", cur_index);
	if (!full_str)
	{
		free(cur_index);
		clean_exit(rt);
	}
	free(cur_index);
	return (full_str);
}

static void	draw_current_obj(t_rt *rt, mlx_t *obj)
{
	char	*full_str;

	mlx_delete_image(obj, rt->instr_img);
	if (rt->obj_sel == OBJ_SEL)
	{
		full_str = check_obj_type(rt);
		rt->instr_img = mlx_put_string(obj, full_str, 5, 5);
		free(full_str);
	}
	else if (rt->obj_sel == LIGHT_SEL)
		rt->instr_img = mlx_put_string(obj, "light", 5, 5);
	else if (rt->obj_sel == CAMERA_SEL)
		rt->instr_img = mlx_put_string(obj, "camera", 5, 5);
}

static void	draw_current_mode(t_rt *rt, mlx_t *obj)
{
	mlx_delete_image(obj, rt->mode_img);
	if (rt->mode == MOVE)
		rt->mode_img = mlx_put_string(obj, "move", 5, 20);
	else if (rt->mode == ROTATE)
		rt->mode_img = mlx_put_string(obj, "rotate", 5, 20);
	else if (rt->mode == SCALE)
		rt->mode_img = mlx_put_string(obj, "scale", 5, 20);
}

bool	draw_gui(t_rt *rt)
{
	mlx_delete_image(rt->mlx, rt->gui_img);
	rt->gui_img = mlx_new_image(rt->mlx, 130, 50);
	draw_back(rt->gui_img);
	if (mlx_image_to_window(rt->mlx, rt->gui_img, 0, 0) == -1)
	{
		mlx_terminate(rt->mlx);
		return (false);
	}
	draw_current_obj(rt, rt->mlx);
	draw_current_mode(rt, rt->mlx);
	rt->needs_render = 0;
	return (true);
}
