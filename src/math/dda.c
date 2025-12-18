/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:58:21 by htrindad          #+#    #+#             */
/*   Updated: 2025/12/18 00:03:36 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Cub3d.h>

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

static inline void	paint_wall(t_rays rays, t_map *map, t_player *player,
		t_img *img)
{
	int		d[3];
	t_img	asset;

	if (!rays.side)
		rays.pwd = rays.dist_x - rays.dx;
	else
		rays.pwd = rays.dist_y - rays.dy;
	rays.pwd *= cos(rays.theta - player->plane_x);
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

	rays = dda_init(player, player->plane_x - FOV * (PI / 180.0f) / 2.0f, 0);
	while (rays.w < WIN_W)
	{
		while (!is_wall(map, rays.map_y, rays.map_x))
			set_vals(&rays, rays.dist_x < rays.dist_y);
		paint_wall(rays, map, player, img);
		rays = dda_init(player, rays.theta + FOV * PI / 180.0f / WIN_W,
				++rays.w);
	}
}
