/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamorim <raamorim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:52:17 by raamorim          #+#    #+#             */
/*   Updated: 2025/10/16 15:35:29 by raamorim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <libft.h>
#include <minilibx-linux/mlx.h>
# include "X11/X.h"
# include "X11/keysym.h"
#include <sys/time.h>
#include <math.h>


#define VALID_CHARS "01NSEW"
#define WALL '1'
#define SPACE '0'
#define ORIENTATION "NSEW"
#define NORTH 'N'
#define SOUTH 'S'
#define WEST 'W'
#define EAST 'E'


#endif