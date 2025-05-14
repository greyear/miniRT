/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:44:46 by azinchen          #+#    #+#             */
/*   Updated: 2025/05/13 12:44:49 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

static int	choose_for_initialization(t_rt *m, char	**args)
{
	int	res;

	res = FAILURE;
	if (!ft_strcmp(args[0], "A"))
		res = init_ambient(m, args);
	else if (!ft_strcmp(args[0], "C"))
		res = init_camera(m, args);
	else if (!ft_strcmp(args[0], "L"))
		res = init_light(m, args);
	else if (!ft_strcmp(args[0], "sp"))
		res = init_sphere(m, args);
	else if (!ft_strcmp(args[0], "pl"))
		res = init_plane(m, args);
	else if (!ft_strcmp(args[0], "cy"))
		res = init_cylinder(m, args);
	return (res);
}

static int	open_file(t_rt *m, char *filename)
{
	m->fd = open(filename, O_RDONLY);
	if (m->fd < 0)
		return (print_err(READ_FILE_MSG));
	return (SUCCESS);
}

static int	process_line(char *line, t_rt *m)
{
	char	**args;

	if (cleaning_line(&line))
	{
		free(line);
		return (SUCCESS);
	}
	args = ft_split(line, ' ');
	if (!args)
	{
		free(line);
		close(m->fd);
		return (print_err(MLLC_MSG));
	}
	if (choose_for_initialization(m, args) == FAILURE)
	{
		free(line);
		ft_clean_arr(&args);
		ft_clean_gnl(m->fd);
		close(m->fd);
		return (FAILURE);
	}
	free(line);
	ft_clean_arr(&args);
	return (SUCCESS);
}

int	init(t_rt *m, char *filename)
{
	char	*line;
	int		return_line;

	if (open_file(m, filename) == FAILURE)
		return (FAILURE);
	line = get_next_line(m->fd);
	while (line)
	{
		return_line = process_line(line, m);
		if (return_line == FAILURE)
			return (FAILURE);
		line = get_next_line(m->fd);
	}
	close(m->fd);
	ft_printf(2, "initiated\n"); //delete
	return (SUCCESS);
}
