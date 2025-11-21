/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulate_rays.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 13:11:08 by htrindad          #+#    #+#             */
/*   Updated: 2025/11/21 13:26:10 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Cub3d.h>

void	ray_cases(t_rays *rays, t_player *player)
{
	if (rays->plane > PI)
	{
		rays->y = (((int)player->y >> 6) << 6) - 0.0001;
		rays->x = (player->y - rays->y) * rays->a_tan + player->x;
		rays->off_y = -64;
		rays->off_x = -rays->off_y * rays->a_tan;
	}
	if (rays->plane < PI)
	{
		rays->y = (((int)player->y >> 6) << 6) + 64;
		rays->x = (player->y - rays->y) * rays->a_tan + player->x;
		rays->off_y = 64;
		rays->off_x = -rays->off_y * rays->a_tan;
	}
	if (!rays->plane || rays->plane == PI)
	{
		rays->y = player->y;
		rays->x = player->x;
		rays->dof = 8;
	}
}
