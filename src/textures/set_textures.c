/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamorim <raamorim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 02:32:49 by rafael            #+#    #+#             */
/*   Updated: 2025/12/09 18:20:08 by raamorim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Cub3d.h>

bool	check_load_textures(char *floor, char *ceiling, t_map *map)
{
	if (!map || !floor || !ceiling)
		return (false);
	if (!map->assets.textures[N].path || !map->assets.textures[S].path
		|| !map->assets.textures[EA].path || !map->assets.textures[WE].path)
		return (false);
	if (!ceiling || !floor)
		return (false);
	return (true);
}

static bool	load_texture(t_img *img, char *path)
{
	if (!img || !path)
		return (false);
	img->path = ft_strdup(path);
	if (!img->path)
		return (false);
	img->img = mlx_xpm_file_to_image(&data_s()->mlx.mlx, img->path, &img->width,
			&img->height);
	if (!img->img)
	{
		return (false);
	}
	img->img_adr = mlx_get_data_addr(img->img, &img->bits_pixel,
			&img->line_len, &img->end);
	if (!img->pixel_ptr)
		return (false);
	return (true);
}

bool	set_texture(char *line, char **floor, char **ceiling, t_map *map)
{
	char	**split;

	split = ft_split(line, ' ');
	if (!split)
		return (ft_putendl_fd("ALLOC ERROR", 2), false);
	if (split[0])
	{
		if (!split[1] || ft_stralen(split) != 2)
			return (free_arr(split), false);
		if (!map->assets.textures[N].path && ft_strncmp(split[0], "NO", 3) == 0)
			load_texture(&map->assets.textures[N], split[1]);
		else if (!map->assets.textures[S].path && ft_strncmp(split[0], "SO",
				3) == 0)
			load_texture(&map->assets.textures[S], split[1]);
		else if (!map->assets.textures[WE].path && ft_strncmp(split[0], "WE",
				3) == 0)
			load_texture(&map->assets.textures[WE], split[1]);
		else if (!map->assets.textures[EA].path && ft_strncmp(split[0], "EA",
				3) == 0)
			load_texture(&map->assets.textures[EA], split[1]);
		else if (!*floor && ft_strncmp(split[0], "F", 2) == 0)
			*floor = ft_strdup(split[1]);
		else if (!*ceiling && ft_strncmp(split[0], "C", 2) == 0)
			*ceiling = ft_strdup(split[1]);
		else
			return (free_arr(split), false);
	}
	return (free_arr(split), true);
}
