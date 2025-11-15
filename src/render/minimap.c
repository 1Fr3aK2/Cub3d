/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:11:21 by htrindad          #+#    #+#             */
/*   Updated: 2025/11/15 17:16:13 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Cub3d.h>

static inline void	draw_sq(size_t y, size_t x, t_rgb color, t_img *img)
{
	const size_t	ly = y * MAP_S + MAP_S;
	const size_t	lx = x * MAP_S + MAP_S;
	size_t		py;
	size_t		px;

	px = x * MAP_S;
	while (px < lx)
	{
		py = y * MAP_S;
		while (py < ly)
			set_color(img, py++, px, color);
		px++;
	}
}

void	draw_minimap(t_data *data)
{
	t_img	*img;
	size_t	y;
	size_t	x;

	img = &data->mlx.img;
	y = 0;
	while (data->map.map[y])
	{
		x = 0;
		while (data->map.map[y][x])
		{
			if (data->map.map[y][x] == '1')
				draw_sq(y, x++, 0xFFFFFF, img);
			else
				draw_sq(y, x++, 0, img);
		}
		y++;
	}
}
