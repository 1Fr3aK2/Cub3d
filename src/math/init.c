/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 19:04:17 by htrindad          #+#    #+#             */
/*   Updated: 2025/12/10 16:58:10 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Cub3d.h>

static inline void	steps(t_rays *rays)
{
	if (rays->dir_y < 0)
	{
		rays->sy = -1;
		rays->dist_y = (rays->y - (int)rays->y) * rays->dy;
	}
	else
	{
		rays->sy = 1;
		rays->dist_y = ((int)rays->y + 1.0 - rays->y) * rays->dy;
	}
	if (rays->dir_x < 0)
	{
		rays->sx = -1;
		rays->dist_x = (rays->x - (int)rays->x) * rays->dy;
	}
	else
	{
		rays->sx = 1;
		rays->dist_x = ((int)rays->x + 1.0 - rays->x) * rays->dx;
	}
}

t_rays	dda_init(t_player *player, float angle, size_t w)
{
	t_rays	rays;

	rays.y = player->y;
	rays.x = player->x;
	rays.map_y = (int)player->y;
	rays.map_x = (int)player->x;
	rays.dir_y = player->dir_y;
	rays.dir_x = player->dir_x;
	rays.theta = angle;
	rays.w = w;
	if (!rays.dir_y)
		rays.dy = 1e30;
	else
		rays.dy = fabsf(1 / rays.dir_y);
	if (!rays.dir_x)
		rays.dx = 1e30;
	else
		rays.dx = fabsf(1 / rays.dir_x);
	steps(&rays);
	return (rays);
}

float	get_dist(t_rays rays)
{
	if (rays.dist_x < rays.dist_y)
		return (rays.dist_x - rays.dx);
	return (rays.dist_y - rays.dy);
}
