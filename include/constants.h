/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:20:50 by azinchen          #+#    #+#             */
/*   Updated: 2025/04/09 14:22:07 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef WIN_WIDTH
#  define WIN_WIDTH 2000
# endif

# ifndef WIN_HEIGHT
#  define WIN_HEIGHT 1000
# endif

# ifndef HEX_LEN
#  define HEX_LEN 8
# endif

# define ERR_MSG "Error\n"
# define ARG_ERR_MSG "./miniRT should take exactly one *.rt argument\n"
# define WRONG_FILENAME_MSG "File is not *.rt\n"
# define FOLDER_MSG "Argument should be a *.rt file\n"
# define READ_FILE_MSG "File cannot be read\n"
# define NO_ELEM_MSG "No elements found\n"
# define DB_ELEM_MSG "Elements which are defined by a capital letter can only \
	be declared once\n"
# define VALID_MSG "Scene file has invalid lines\n"
# define AMBIENT_ARGS "Ambient lightning has wrong number of arguments\n"
# define CAMERA_ARGS "Camera has wrong number of arguments\n"
# define LIGHT_ARGS "Light has wrong number of arguments\n"
# define SPHERE_ARGS "Sphere has wrong number of arguments\n"
# define PLANE_ARGS "Plane has wrong number of arguments\n"
# define CYLINDER_ARGS "Cylinder has wrong number of arguments\n"
# define NUM_MSG "Invalid number: \n"
# define RANGE_MSG " is out of range\n"
# define EMPTY_MSG "Empty string\n"
# define MINUS_MSG "Number cannot be just a minus\n"
# define FORBID_MSG "Forbidden symbol in number\n"
# define DOTS_MSG "Multiple dots in double\n"
# define BEF_DOT_MSG "Dot cannot be the 1st symbol or follow minus\n"
# define AFT_DOT_MSG "Dot cannot be the lst symbol\n"
# define DIGIT_MSG "Double should contain at least one digit\n"
# define MLLC_MSG "Malloc failure\n"
