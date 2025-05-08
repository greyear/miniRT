/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:39:06 by azinchen          #+#    #+#             */
/*   Updated: 2025/04/09 14:46:34 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
only 1 argiment
file only *.rt and not a folder, permissions
file is not empty
absolute path for the file!
file has too many lines (?)
only allowed type identifiers

spaces at the start of the line??

range checks for lightning/brightness ratio (0.0-1.0)
				 color (0-255)
				 normalized vector (-1 to 1)
				 FOV (0-180) whole number
atoi/atof?
only one 1 letter identifier per file

vector: 3 values with commas. can they be without dots?
color: 3 values with commas

figures dieameters and heights - above 0. just 0 cannot be?

*/

/*
переделала на вывод ошибок:
- pre_atoi
- pre_atof
- validate_value
- validate: ratio, color, vector, coordinates, diameter/height, FOV
- int/flt out_of_range
*/