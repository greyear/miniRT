/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filename.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:15:54 by azinchen          #+#    #+#             */
/*   Updated: 2025/04/09 13:12:47 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	name_check(char *name)
{
	int	l;

	l = ft_strlen(name);
	if (l < 4 || name[l - 1] != 't' || name[l - 2] != 'r'
		|| name[l - 3] != '.')
	{
		ft_putstr_fd("File is not *.rt\n", 2);
		exit(EXIT_FAILURE); //chech cleaning
	}
}

void	dir_check(char *name)
{
	DIR	*dir;

	dir = opendir(name);
	if (dir)
	{
		closedir(dir);
		ft_putstr_fd("Argument should be a *.rt file\n", 2);
		exit(EXIT_FAILURE);
	}
}
