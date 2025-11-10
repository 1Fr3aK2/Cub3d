/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 17:38:38 by htrindad          #+#    #+#             */
/*   Updated: 2025/11/10 10:45:47 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Cub3d.h>

static inline void	paint_bg(t_rgb floor, t_rgb ceiling, t_img *img)
{
	size_t	y;
	size_t	x;
	int		offset;
	t_rgb	cc;

	x = 0;
	while (x < WIN_W)
	{
		y = 0;
		cc = ceiling;
		while (y < WIN_H)
		{
			offset = (img->line_len * y) + (x * (img->bits_pixel / 8));
			*((unsigned int *)(offset + img->pixel_ptr)) = cc;
			if (++y > (WIN_H / 2) && cc == ceiling)
				cc = floor;
		}
		x++;
	}

}

static void	set_fc(t_data *data)
{
	t_rgb	floor;
	t_rgb	ceiling;
	t_img	*img;

	floor = set_rgb(data->map.floor, data);
	ceiling = set_rgb(data->map.ceiling, data);
	img = &data->mlx.img;
	img->pixel_ptr = mlx_get_data_addr(img->img, &img->bits_pixel, &img->line_len, &img->end);
	paint_bg(floor, ceiling, img);
}

int	render(t_data *data)
{
	set_fc(data);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->mlx.img.img, 0, 0);
	return (0);
}
