/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamorim <raamorim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 12:47:57 by htrindad          #+#    #+#             */
/*   Updated: 2025/11/27 18:57:34 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Cub3d.h>

t_limits	set_limits(float x, float y)
{
	t_limits	limit;

	limit.x = x;
	limit.y = y;
	return (limit);
}

t_paint	paint_init(void)
{
	t_paint	paint;

	paint.color = 0;
	paint.x = 0;
	paint.y = 0;
	paint.begin = set_limits(0, 0);
	paint.end = set_limits(0, 0);
	return (paint);
}

t_paint	set_dimensions(t_rgb color, t_paint c_paint, t_limits begin,
		t_limits end)
{
	c_paint.color = color;
	c_paint.begin = begin;
	c_paint.end = end;
	return (c_paint);
}
