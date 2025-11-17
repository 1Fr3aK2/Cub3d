/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 15:24:16 by htrindad          #+#    #+#             */
/*   Updated: 2025/11/16 17:37:03 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Cub3d.h>

void	draw_player_pos(t_player *player, t_img *img)
{
	float	x;
	float	y;

	x = player->x;
	y = player->y;
	draw_sq(set_dimensions(ft_rgb(0, 255, 0), paint_init(),
			set_limits(x * SQ_SIZE, y * SQ_SIZE),
			set_limits(x * SQ_SIZE + (SQ_SIZE / 4), y * SQ_SIZE + (SQ_SIZE / 4)))
			, img);
}
