/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filename.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:15:54 by azinchen          #+#    #+#             */
/*   Updated: 2025/04/09 14:08:08 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

int	arg_check(int argc)
{
	if (argc != 2)
		return (print_err(ARG_ERR_MSG));
	return (SUCCESS);
}

int	name_check(char *name)
{
	int	l;

	l = ft_strlen(name);
	if (l < 4 || name[l - 1] != 't' || name[l - 2] != 'r'
			|| name[l - 3] != '.')
		return (print_err(WRONG_FILENAME_MSG));
	return (SUCCESS);
}

int	dir_check(char *name)
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

int	validation(char *argv[])
{
	int	fd;

	if (!name_check(argv[1]) || !dir_check(argv[1]))
		return(FAILURE);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (print_err(READ_FILE_MSG));

	return (SUCCESS);
}
