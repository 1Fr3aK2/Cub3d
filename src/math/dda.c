/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamorim <raamorim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:58:21 by htrindad          #+#    #+#             */
/*   Updated: 2025/12/10 17:00:06 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Cub3d.h>

static inline void	paint_ray(t_img *img, t_map *map, t_limits start,
		float angle)
{
	float		inc[2];
	t_limits	checker;

	inc[0] = sin(angle);
	inc[1] = cos(angle);
	while (1)
	{
		checker = start;
		set_color(img, start.y * SQ_SIZE, start.x * SQ_SIZE, 255);
		start.y += inc[0] * TRACE;
		start.x += inc[1] * TRACE;
		if (is_wall(map, start.y, start.x) || is_wall(map, checker.y, start.x)
			|| is_wall(map, start.y, checker.x))
			break ;
	}
}

static inline t_img	chose_asset(t_rays rays, t_assets *assets, t_player *player)
{
	if (rays.dist_x < rays.dist_y)
	{
		if (player->x < rays.x)
			return (assets->textures[EA]);
		return (assets->textures[WE]);
	}
	if (player->y > rays.y)
		return (assets->textures[N]);
	return (assets->textures[S]);
}

static inline void	paint_wall(t_rays rays, t_player *player, t_map *map, t_img *img)
{
	int		d[3];
	t_img	asset;

	d[0] = (int)(WIN_H / get_dist(rays));
	d[1] = -d[0] / 2 + WIN_H / 2;
	if (d[1] < 0)
		d[1] = 0;
	d[2] = d[0] / 2 + WIN_H / 2;
	if (d[2] >= WIN_H)
		d[2] = WIN_H - 1;
	asset = chose_asset(rays, &map->assets, player);
	cpy_line(img, asset, rays, d);
}

void	dda(t_player *player, t_map *map, t_img *img)
{
	t_rays	rays;

	rays = dda_init(player, player->plane_x - FOV * (PI / 180.0f) / 2.0f, -1);
	while (++rays.w < WIN_W)
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
		paint_wall(rays, player, map, img);
		paint_ray(img, map, set_limits(player->x, player->y), rays.theta);
		rays = dda_init(player, rays.theta + FOV * PI / 180.0f / WIN_W, rays.w);
	}
}
