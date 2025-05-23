/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:15:54 by azinchen          #+#    #+#             */
/*   Updated: 2025/04/14 17:56:25 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mini_rt.h"

static int	arg_check(int argc)
{
	if (argc != 2)
		return (print_err(ARG_ERR_MSG));
	return (SUCCESS);
}

static int	name_check(char *name)
{
	int	l;

	l = ft_strlen(name);
	if (l < 4 || name[l - 1] != 't' || name[l - 2] != 'r'
		|| name[l - 3] != '.')
		return (print_err(WRONG_FILENAME_MSG));
	return (SUCCESS);
}

static int	dir_check(char *name)
{
	DIR	*dir;

	dir = opendir(name);
	if (dir != NULL)
	{
		closedir(dir);
		return (print_err(FOLDER_MSG));
	}
	return (SUCCESS);
}

int	validation(t_rt *m, int argc, char *argv[])
{
	if (arg_check(argc) || name_check(argv[1]) || dir_check(argv[1]))
		return (FAILURE);
	m->fd = open(argv[1], O_RDONLY);
	if (m->fd < 0)
		return (print_err(READ_FILE_MSG));
	if (validate_content(m) == FAILURE)
	{
		close(m->fd);
		return (FAILURE);
	}
	close(m->fd);
	return (SUCCESS);
}
