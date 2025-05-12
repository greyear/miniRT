
#include "../../include/miniRT.h"

static int	choose_for_initialization(t_miniRT *m, char	**args)
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

int	init(t_miniRT *m, char *filename)
{
	char	*line;
	char	**args;

	m->fd = open(filename, O_RDONLY);
	if (m->fd < 0)
		return (print_err(READ_FILE_MSG));
	line = get_next_line(m->fd);
	while (line)
	{
		if (cleaning_line(&line))
		{
			free(line);
			line = get_next_line(m->fd);
			continue ;
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
		line = get_next_line(m->fd);
	}
	close(m->fd);
	ft_printf(2, "initiated\n"); //delete
	return (SUCCESS);
}
