/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:58:21 by htrindad          #+#    #+#             */
/*   Updated: 2025/11/27 20:39:05 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Cub3d.h>

void	dda(t_player *player, t_map *map, t_img *img)
{
	t_rays	rays;

	rays = dda_init(player);
	while (!is_wall(map, rays.map_y, rays.map_x))
	{
		if (rays.dist_x < rays.dist_y)
		{
			rays.dist_x += rays.dx;
			rays.map_x += rays.sx;
			rays.x += rays.sx;
			set_color(img, rays.y * SQ_SIZE, rays.x * SQ_SIZE, 255);
		}
		else
		{
			rays.dist_y += rays.dy;
			rays.map_y += rays.sy;
			rays.y += rays.sy;
			set_color(img, rays.y * SQ_SIZE, rays.x * SQ_SIZE, 255);
		}
	}
}
