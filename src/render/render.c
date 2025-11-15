/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamorim <raamorim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 17:38:38 by htrindad          #+#    #+#             */
/*   Updated: 2025/11/15 17:14:23 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Cub3d.h>

void	set_color(t_img *img, size_t y, size_t x, t_rgb cc)
{
	int	offset;

	offset = (img->line_len * y) + (x * (img->bits_pixel / 8));
	*((unsigned int *)(offset + img->pixel_ptr)) = cc;
}

static inline void	paint_bg(t_rgb floor, t_rgb ceiling, t_img *img)
{
	size_t	y;
	size_t	x;
	t_rgb	cc;

	x = 0;
	while (x < WIN_W)
	{
		y = 0;
		cc = ceiling;
		while (y < WIN_H)
		{
			set_color(img, y, x, cc);
			if (++y > (WIN_H / 2) && cc == ceiling)
				cc = floor;
		}
		x++;
	}
}

static void	set_fc(t_data *data)
{
	t_img	*img;
	t_rgb	floor;
	t_rgb	ceiling;

	floor = data->map.rgb_floor;
	ceiling = data->map.rgb_ceiling;
	img = &data->mlx.img;
	img->pixel_ptr = mlx_get_data_addr(img->img, &img->bits_pixel,
			&img->line_len, &img->end);
	paint_bg(floor, ceiling, img);
}

int	render(t_data *data)
{
	set_fc(data);
	draw_minimap(data);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->mlx.img.img, 0,
		0);
	return (0);
}
