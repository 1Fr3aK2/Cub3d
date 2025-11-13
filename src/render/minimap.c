/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:11:21 by htrindad          #+#    #+#             */
/*   Updated: 2025/11/13 17:55:23 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Cub3D.h>

static inline void	draw_sq(size_t y, size_t x, t_rgb white, t_img *img)
{
	const size_t	ly = y * (MAP_S << 1);
	const size_t	lx = x * (MAP_S << 1);
	size_t		py;
	size_t		px;

	py = y * MAP_S + 1;
	px = x * MAP_S + 1;
	while (px < lx - 1)
	{
		while (py < ly - 1)
			set_color(img, py++, px, white);
		px++;
	}
}

void	draw_minimap(t_data *data)
{
	t_img	*img;

	img = &data->mlx.img;
}
