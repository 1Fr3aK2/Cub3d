/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 17:38:38 by htrindad          #+#    #+#             */
/*   Updated: 2025/12/11 00:31:30 by rafael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Cub3d.h>

void	set_color(t_img *img, size_t y, size_t x, t_rgb cc)
{
	int	offset;

	offset = (img->line_len * y) + (x * (img->bits_pixel / 8));
	*((unsigned int *)(offset + img->pixel_ptr)) = cc;
}

void	cpy_line(t_img *img, t_img asset, t_rays ray, int d[3])
{
	const size_t	tex_h = 64; // TODO, this is an arbitrary value. The assets need to be checked if they are squares
	double		ts;
	double		tp;
	int			ty;

	ts = (double)tex_h / d[0];
	tp = (d[1] - WIN_H / 2 + d[0] / 2) * ts;
	while (d[1] < d[2])
	{
		ty = (int)tp;
		tp += ts;
		set_color(img, d[1], ray.w, get_rgb(&asset, ty, ray.w));
		d[1]++;
	}
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

static void	set_fc(t_data *data, t_img *img)
{
	t_rgb	floor;
	t_rgb	ceiling;

	floor = data->map.rgb_floor;
	ceiling = data->map.rgb_ceiling;
	paint_bg(floor, ceiling, img);
}

int	render(t_data *data)
{
	t_img	*img;

	movements(data);
	img = &data->mlx.img;
	img->pixel_ptr = mlx_get_data_addr(img->img, &img->bits_pixel,
			&img->line_len, &img->end);
	set_fc(data, img);
	draw_minimap(data, img);
	draw_player_pos(&data->player, img);
	dda(&data->player, &data->map, img);
	compass_setter(&data->player, img);
	dda(&data->player, &data->map, img);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->mlx.img.img, 0,
		0);
	return (0);
}
