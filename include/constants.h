/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:20:50 by azinchen          #+#    #+#             */
/*   Updated: 2025/05/01 13:35:09 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H

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
# define AMBIENT_ARGS "Ambient: wrong number of arguments\n"
# define CAMERA_ARGS "Camera: wrong number of arguments\n"
# define LIGHT_ARGS "Light: wrong number of arguments\n"
# define SPHERE_ARGS "Sphere: wrong number of arguments\n"
# define PLANE_ARGS "Plane: wrong number of arguments\n"
# define CYLINDER_ARGS "Cylinder: wrong number of arguments\n"
# define NUM_MSG "Invalid number: \n"
# define RANGE_MSG "is out of range\n"
# define EMPTY_MSG "empty string\n"
# define MINUS_MSG "number cannot be just a minus\n"
# define FORBID_MSG "is not a valid number\n"
# define DOTS_MSG "multiple dots in float\n"
# define BEF_DOT_MSG "dot cannot be the 1st symbol or follow minus\n"
# define AFT_DOT_MSG "dot cannot be the last symbol\n"
# define DIGIT_MSG "float should contain at least one digit\n"
# define COMP_MSG "wrong number of components\n"
# define CONFL_MSG "number should be int or float not both\n"
# define ATON_MSG "atoi/atof failed\n"
# define UNKNOWN_MSG "Unknown validation error\n"
# define MLLC_MSG "memory allocation failed\n"

# ifndef MAX_DEPTH
#  define MAX_DEPTH 3
# endif

# ifndef PIXEL_SAMPLES
#  define PIXEL_SAMPLES 4
# endif

# ifndef BIAS
#  define BIAS 1e-4
# endif

#endif
