/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:11:21 by htrindad          #+#    #+#             */
/*   Updated: 2025/11/16 15:27:54 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Cub3d.h>

void	draw_sq(t_paint paint, t_img *img)
{
	const size_t	reset = paint.begin.y;
	t_limits	begin;
	t_limits	end;

	begin = paint.begin;
	end = paint.end;
	while (begin.x < end.x && begin.x < WIN_W)
	{
		begin.y = reset;
		while (begin.y < end.y && begin.y < WIN_H)
			set_color(img, begin.y++, begin.x, paint.color);
		begin.x++;
	}
}

static inline t_paint	condition(char **map, t_paint paint, t_img *img)
{
	if (paint.x < ft_strlen(map[paint.y]))
	{
		if (map[paint.y][paint.x] == '1')
			draw_sq(set_dimensions(0xFFFFFF, paint,
					set_limits(paint.x * SQ_SIZE, paint.y * SQ_SIZE),
					set_limits(paint.x * SQ_SIZE + SQ_SIZE, paint.y * SQ_SIZE + SQ_SIZE))
					, img);
		else
			draw_sq(set_dimensions(0, paint,
					set_limits(paint.x * SQ_SIZE, paint.y * SQ_SIZE),
					set_limits(paint.x * SQ_SIZE + SQ_SIZE, paint.y * SQ_SIZE + SQ_SIZE))
					, img);
	}
	paint.y++;
	return (paint);
}

void	draw_minimap(t_data *data, t_img *img)
{
	const size_t	max_w = data->map.max_w;
	const size_t	max_h = data->map.max_h;
	t_paint			paint;

	paint = paint_init();
	while (paint.y < max_h)
	{
		if (paint.x > ft_strlen(data->map.map[paint.y]))
		{
			paint.y++;
			continue;
		}
		while (data->map.map[paint.y] && paint.x < max_w)
			paint = condition(data->map.map, paint, img);
		paint.x++;
		paint.y = 0;
	}
}
