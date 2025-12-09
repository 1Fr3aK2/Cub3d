/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamorim <raamorim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 02:32:49 by rafael            #+#    #+#             */
/*   Updated: 2025/12/09 17:29:42 by raamorim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Cub3d.h>

bool	check_load_textures(char *floor, char *ceiling, t_map *map)
{
	if (!map || !floor || !ceiling)
		return (false);
	if (!map->assets.textures[N].path || !map->assets.textures[S].path|| !map->assets.textures[EA].path || !map->assets.textures[WE].path)
		return (false);
	if (!ceiling || !floor)
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
		if (split[1] == NULL || ft_stralen(split) != 2)
			return (free_arr(split), false);
		if (map->assets.textures[N].path == NULL && ft_strncmp(split[0], "NO", 3) == 0)
			map->assets.textures[N].path = ft_strdup(split[1]);
		else if (map->assets.textures[S].path == NULL && ft_strncmp(split[0], "SO", 3) == 0)
			map->assets.textures[S].path = ft_strdup(split[1]);
		else if (map->assets.textures[WE].path == NULL && ft_strncmp(split[0], "WE", 3) == 0)
			map->assets.textures[WE].path = ft_strdup(split[1]);
		else if (map->assets.textures[EA].path == NULL && ft_strncmp(split[0], "EA", 3) == 0)
			map->assets.textures[EA].path = ft_strdup(split[1]);
		else if (*floor == NULL && ft_strncmp(split[0], "F", 2) == 0)
			*floor = ft_strdup(split[1]);
		else if (*ceiling == NULL && ft_strncmp(split[0], "C", 2) == 0)
			*ceiling = ft_strdup(split[1]);
		else
			return (free_arr(split), false);
	}
	return (free_arr(split), true);
}
