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
Cases to consider:

1) 0,0,0 normalized vector. Is it okay or not in the end?

2) Camera: orientation vector [-1,1] but I have less
C -50,1,20 1,0,-1.0000000000001 180

3) Additional comma after all 3 coordinates
L -40,0,30, 0.7

4) 0 diameter/height? -0?

5) if there's no line with L should we still store 0s? 3 flags for existence?

6) 

*/