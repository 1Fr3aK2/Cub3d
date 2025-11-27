/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertice.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamorim <raamorim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 11:56:19 by htrindad          #+#    #+#             */
/*   Updated: 2025/11/27 20:34:22 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Cub3d.h>

static inline uint8_t	get_arr(float b[2], float e[2], bool up_y, bool up_x)
{
	uint8_t	condition;

	condition = 0;
	if (up_y)
	{
		if (b[0] <= e[0])
			condition |= 1 << 0;
	}
	else if (b[0] >= e[0])
		condition |= 1 << 0;
	if (up_x)
	{
		if (b[1] <= e[1])
			condition |= 1 << 1;
	}
	else if (b[1] >= e[1])
		condition |= 1 << 1;
	return (condition);
}

void	draw_vertice(t_paint paint, t_img *img, float dir_y,
		float dir_x)
{
	bool	up_y;
	bool	up_x;
	uint8_t	condition;
	float	b[2];
	float	e[2];

	condition = 0;
	b[0] = paint.begin.y;
	b[1] = paint.begin.x;
	e[0] = paint.end.y;
	e[1] = paint.end.x;
	up_y = (b[0] > e[0]);
	up_x = (b[1] > e[1]);
	while (condition != 3)
	{
		condition = get_arr(b, e, up_y, up_x);
		set_color(img, b[0], b[1], paint.color);
		b[0] += dir_y;
		b[1] += dir_x;
	}
}

void	compass_setter(t_player *player, t_img *img)
{
	t_paint	paint;

	paint = set_dimensions(ft_rgb(255, 255, 0), paint_init(),
			set_limits(player->x * SQ_SIZE, player->y * SQ_SIZE),
			set_limits(player->x * SQ_SIZE + player->dir_x * C_SIZE, player->y
				* SQ_SIZE + player->dir_y * C_SIZE));
	draw_vertice(paint, img, player->dir_y, player->dir_x);
}
