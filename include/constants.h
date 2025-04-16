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
