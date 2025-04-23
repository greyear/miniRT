/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:20:50 by azinchen          #+#    #+#             */
/*   Updated: 2025/04/14 11:50:07 by msavelie         ###   ########.fr       */
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

# ifndef MAX_DEPTH
#  define MAX_DEPTH 3
# endif

# ifndef PIXEL_SAMPLES
#  define PIXEL_SAMPLES 6 //12
# endif

# ifndef VEC_ADD
#  define VEC_ADD(a, b) ((t_vector){ (a).x + (b).x, (a).y + (b).y, (a).z + (b).z })
# endif

# ifndef VEC_SUB
#  define VEC_SUB(a, b) ((t_vector){ (a).x - (b).x, (a).y - (b).y, (a).z - (b).z })
# endif

# ifndef VEC_MUL
#  define VEC_MUL(a, b) ((t_vector){ (a).x * (b).x, (a).y * (b).y, (a).z * (b).z })
# endif

# ifndef VEC_MULF
#  define VEC_MULF(a, f) ((t_vector){ (a).x * (f), (a).y * (f), (a).z * (f) })
# endif