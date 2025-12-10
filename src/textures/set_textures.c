/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamorim <raamorim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 02:32:49 by rafael            #+#    #+#             */
/*   Updated: 2025/12/10 17:00:13 by raamorim         ###   ########.fr       */
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
		return (false);
	img->pixel_ptr = mlx_get_data_addr(img->img, &img->bits_pixel,
			&img->line_len, &img->end);
	if (!img->pixel_ptr)
		return (false);
	if (img->width != img->height)
		return (false);
	return (true);
}
bool	set_assets_texture(t_assets *assets, char **path)
{
	if (!assets || !path || !*path)
		return (false);
	if (!assets->textures[N].path && ft_strncmp(path[0], "NO", 3) == 0)
		return (load_texture(&assets->textures[N], path[1]));
	else if (!assets->textures[S].path && ft_strncmp(path[0], "SO",
			3) == 0)
		return (load_texture(&assets->textures[S], path[1]));
	else if (!assets->textures[WE].path && ft_strncmp(path[0], "WE",
			3) == 0)
		return (load_texture(&assets->textures[WE], path[1]));
	else if (!assets->textures[EA].path && ft_strncmp(path[0], "EA",
			3) == 0)
		return (load_texture(&assets->textures[EA], path[1]));
	return (false);
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
		if (set_assets_texture(&map->assets, split))
			return (free_arr(split), true);
		if (!*floor && ft_strncmp(split[0], "F", 2) == 0)
			*floor = ft_strdup(split[1]);
		else if (!*ceiling && ft_strncmp(split[0], "C", 2) == 0)
			*ceiling = ft_strdup(split[1]);
		// else
		// 	return (free_arr(split), false);
	}
	return (free_arr(split), true);
}
