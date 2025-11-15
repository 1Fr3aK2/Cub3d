/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:11:21 by htrindad          #+#    #+#             */
/*   Updated: 2025/11/15 19:24:09 by htrindad         ###   ########.fr       */
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
	while (px < lx && px < WIN_W)
	{
		py = y * MAP_S;
		while (py < ly && py < WIN_H)
			set_color(img, py++, px, color);
		px++;
	}
}

void	draw_minimap(t_data *data, t_img *img)
{
	const size_t	max_w = data->map.max_w;
	const size_t	max_h = data->map.max_h;
	size_t		y;
	size_t		x;

	y = 0;
	x = 0;
	while (y < max_h - 1)
	{
		while (x < max_w)
		{
			if (x > ft_strlen(data->map.map[y]))
			{
				y++;
				continue;
			}
			else if (data->map.map[y][x] == '1')
				draw_sq(y++, x, 0xFFFFFF, img);
			else
				draw_sq(y++, x, 0, img);
		}
		x++;
		y = 0;
	}
}
