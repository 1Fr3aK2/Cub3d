/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:58:21 by htrindad          #+#    #+#             */
/*   Updated: 2025/12/16 18:53:06 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Cub3d.h>

void	paint_ray(t_img *img, t_map *map, t_limits start,
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

static inline t_img	chose_asset(t_rays rays, t_assets *assets)
{
	if (!rays.side)
	{
		if (rays.dir_x > 0)
			return (assets->textures[EA]);
		return (assets->textures[WE]);
	}
	else
	{
		if (rays.dir_y > 0)
			return (assets->textures[S]);
	}
	return (assets->textures[N]);
}

static inline void	paint_wall(t_rays rays, t_map *map, t_img *img)
{
	int		d[3];
	t_img	asset;

	if (!rays.side)
		rays.pwd = rays.dist_x - rays.dx;
	else
		rays.pwd = rays.dist_y - rays.dy;
	d[0] = (int)(WIN_H / rays.pwd);
	d[1] = -d[0] / 2 + WIN_H / 2;
	if (d[1] < 0)
		d[1] = 0;
	d[2] = d[0] / 2 + WIN_H / 2;
	if (d[2] >= WIN_H)
		d[2] = WIN_H - 1;
	asset = chose_asset(rays, &map->assets);
	cpy_line(img, asset, rays, d);
}

void	dda(t_player *player, t_map *map, t_img *img)
{
	t_rays	rays;

	rays = dda_init(player, player->plane_x - FOV * (PI / 180.0f) / 2.0f, -1);
	while (++rays.w < WIN_W)
	{
		while (!is_wall(map, rays.map_y, rays.map_x))
			set_vals(&rays, rays.dist_x < rays.dist_y);
		paint_ray(img, map, set_limits(player->x, player->y), rays.theta);
		paint_wall(rays, map, img);
		rays = dda_init(player, rays.theta + FOV * PI / 180.0f / WIN_W, rays.w);
	}
}
