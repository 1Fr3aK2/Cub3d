/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:58:21 by htrindad          #+#    #+#             */
/*   Updated: 2025/12/01 17:03:53 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Cub3d.h>

static inline void	paint_ray(t_img *img, t_map *map, t_limits start, float angle)
{
	float			inc[2];
	t_limits	checker;

	inc[0] = sin(angle);
	inc[1] = cos(angle);
	while (1)
	{
		checker = start;
		set_color(img, start.y * SQ_SIZE, start.x * SQ_SIZE, 255);
		start.y += inc[0] * TRACE;
		start.x += inc[1] * TRACE;
		if (is_wall(map, start.y, checker.x)
			|| is_wall(map, checker.y, start.x)
			|| is_wall(map, start.y, start.x))
			break ;
	}
}

void	dda(t_player *player, t_map *map, t_img *img)
{
	t_rays	rays;
	size_t	w;

	rays = dda_init(player, player->plane_x - FOV * (PI / 180.0f) / 2.0f);
	w = -1;
	while (++w < WIN_W)
	{
		while (!is_wall(map, rays.map_y, rays.map_x))
		{
			if (rays.dist_x < rays.dist_y)
			{
				rays.dist_x += rays.dx;
				rays.map_x += rays.sx;
				rays.x += rays.sx;
			}
			else
			{
				rays.dist_y += rays.dy;
				rays.map_y += rays.sy;
				rays.y += rays.sy;
			}
		}
		paint_ray(img, map, set_limits(player->x, player->y), rays.theta);
		rays = dda_init(player, rays.theta + FOV * PI / 180.0f / WIN_W);
	}
}
