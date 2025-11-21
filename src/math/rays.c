/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 13:01:23 by htrindad          #+#    #+#             */
/*   Updated: 2025/11/21 13:37:46 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Cub3d.h>

void	ray_process(t_player *player, t_img *img, t_rays rays, t_map *map)
{
	size_t	r;

	r = 0;
	while (r < 0)
	{
		rays.a_tan = -tan(rays.plane);
		ray_cases(&rays, player);
		while (rays.dof < 8)
		{
			rays.map_x = (size_t)rays.x >> 6;
			rays.map_y = (size_t)rays.y >> 6;
			if (is_wall(map, rays))
		}
		r++;
	}
}

t_rays	init_rays(t_player *player)
{
	t_rays	rays;

	rays.plane = player->plane_x;
	rays.y = player->y;
	rays.x = player->x;
	rays.a_tan = 0;
	return (rays);
}
