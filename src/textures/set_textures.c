/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 02:32:49 by rafael            #+#    #+#             */
/*   Updated: 2025/12/03 00:18:59 by rafael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

bool	check_load_textures(char *floor, char *ceiling, t_map *map)
{
	int	i;

	if (!map || !floor || !ceiling)
		return (false);
	i = 0;
	while (i < 4)
	{
		if (!map->textures[i].path)
			return (false);
		i++;
	}
	return (true);
}

static int	get_asset_type(char *id)
{
	if (!ft_strncmp(id, "EA", 2))
		return (EA);
	if (!ft_strncmp(id, "WE", 2))
		return (WE);
	if (!ft_strncmp(id, "NO", 2))
		return (NO);
	if (!ft_strncmp(id, "SO", 2))
		return (SO);
	return (-1);
}

bool	set_texture(char *line, t_map *map)
{
	char	**split;
	int		type;

	if (!line || !map)
		return (false);
	split = ft_split(line, ' ');
	if (!split || !split[0] || !split[1])
	{
		free_arr(split);
		return (false);
	}
	type = get_asset_type(split[0]);
	if (type < 0)
	{
		free_arr(split);
		return (false);
	}
	map->textures[type].id = ft_strdup(split[0]);
	map->textures[type].path = ft_strdup(split[1]);
	free_arr(split);
	return (map->textures[type].path != NULL);
}
