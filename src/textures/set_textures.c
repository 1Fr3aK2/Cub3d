/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 02:32:49 by rafael            #+#    #+#             */
/*   Updated: 2025/11/08 03:53:49 by rafael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Cub3d.h>

bool check_load_textures(t_map *map)
{
	if (!map)
		return (false);
	if (!map->north || !map->south || !map->east || !map->east)
		return (false);
	if (!map->ceiling || !map->floor)
		return (false);
	return (true);
}


bool	set_texture(char *line, t_map *map)
{
	char **split;

	split = ft_split(line, ' ');
	if (!split)
		return (ft_putendl_fd("ALLOC ERROR", 2), false);
	if (split[0])
	{
		if (split[1] == NULL || ft_stralen(split) != 2)
			return (free_arr(split), false);
		if (map->north == NULL && ft_strncmp(split[0], "NO", 3) == 0)
			map->north = ft_strdup(split[1]);
		else if (map->south == NULL && ft_strncmp(split[0], "SO", 3) == 0)
			map->south = ft_strdup(split[1]);
		else if (map->west == NULL && ft_strncmp(split[0], "WE", 3) == 0)
			map->west = ft_strdup(split[1]);
		else if (map->east == NULL && ft_strncmp(split[0], "EA", 3) == 0)
			map->east = ft_strdup(split[1]);
		else if (map->ceiling == NULL && ft_strncmp(split[0], "C", 2) == 0)
			map->ceiling = ft_strdup(split[1]);
		else if (map->floor == NULL && ft_strncmp(split[0], "F", 2) == 0)
			map->floor = ft_strdup(split[1]);
		else
			return (free_arr(split), false);
	}
	return (free_arr(split), true);
}