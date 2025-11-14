/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:11:21 by htrindad          #+#    #+#             */
/*   Updated: 2025/11/14 15:41:13 by rafael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Cub3D.h>

static inline void	draw_sq(size_t y, size_t x, t_rgb white, t_img *img)
{
	const size_t	ly = y * MAP_S + MAP_S;
	const size_t	lx = x * MAP_S + MAP_S;
	size_t		py;
	size_t		px;

	py = y * MAP_S;
	px = x * MAP_S;
	while (px < lx)
	{
		while (py < ly)
			set_color(img, py++, px, white);
		px++;
	}
}

void	draw_minimap(t_data *data)
{
	t_img	*img;

	img = &data->mlx.img;
}
