/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 13:01:23 by htrindad          #+#    #+#             */
/*   Updated: 2025/11/21 17:32:17 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Cub3d.h>

t_rays	init_rays(t_player *player)
{
	t_rays	rays;

	rays.plane = player->plane_x;
	rays.y = player->y;
	rays.x = player->x;
	rays.a_tan = 0;
	return (rays);
}

void	ray_process(t_player *player, t_img *img, t_map *map)
{
	t_rays	rays;

	rays = init_rays(player);
	rays.a_tan = -1/tan(rays.plane);
	ray_cases(&rays, player);
	while (rays.dof < 8)
	{
		rays.map_x = (size_t)rays.x >> 4;
		rays.map_y = (size_t)rays.y >> 4;
		if (is_wall(map, rays.y, rays.x))
			rays.dof = 8;
		else
		{
			rays.y += rays.off_y;
			rays.x += rays.off_x;
			rays.dof++;
		}
	}
	draw_vertice(set_dimensions(255, paint_init(),
				set_limits(player->x * SQ_SIZE, player->y * SQ_SIZE),
				set_limits(rays.x * SQ_SIZE, rays.y * SQ_SIZE)),
				img, rays.off_y, rays.off_x);
}
