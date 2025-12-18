/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 17:50:04 by htrindad          #+#    #+#             */
/*   Updated: 2025/12/10 16:43:03 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Cub3d.h>

t_rgb	set_rgb(char *strrgb, t_data *data)
{
	char	**strrgb_bi;
	uint8_t	rgb[3];
	size_t	i;

	strrgb_bi = ft_split(strrgb, ',');
	if (strrgb_bi == NULL)
		exit_error(data, "ERROR: Malloc fail");
	i = -1;
	while (++i < 3)
		rgb[i] = ft_atob(strrgb_bi[i]);
	free_arr(strrgb_bi);
	return (ft_rgb(rgb[0], rgb[1], rgb[2]));
}

t_rgb	get_rgb(t_img *img, size_t y, size_t x)
{
	const int	offset = (img->line_len * y) + (x * (img->bits_pixel / 8));

	return (*((t_rgb *)(img->pixel_ptr + offset)));
}
