/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 02:32:49 by rafael            #+#    #+#             */
/*   Updated: 2025/12/03 17:30:12 by rafael           ###   ########.fr       */
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

static int	handle_fc(char **split, char **floor, char **ceiling)
{
	if (ft_strncmp(split[0], "F", 2) == 0)
	{
		if (*floor != NULL)
			return (0);
		*floor = ft_strdup(split[1]);
		if (*floor != NULL)
			return (1);
		return (0);
	}
	if (ft_strncmp(split[0], "C", 2) == 0)
	{
		if (*ceiling != NULL)
			return (0);
		*ceiling = ft_strdup(split[1]);
		if (*ceiling != NULL)
			return (1);
		return (0);
	}
	return (-1);
}

static bool	handle_texture(t_map *map, char **split)
{
	int	type;

	type = get_asset_type(split[0]);
	if (type < 0 || map->textures[type].path != NULL)
		return (false);
	map->textures[type].id = ft_strdup(split[0]);
	map->textures[type].path = ft_strdup(split[1]);
	return (map->textures[type].path != NULL);
}

bool	set_texture(char *line, char **floor, char **ceiling, t_map *map)
{
	char	**split;
	int		fc;

	if (!line || !map)
		return (false);
	split = ft_split(line, ' ');
	if (!split || !split[0] || !split[1] || ft_stralen(split) != 2)
		return (free_arr(split), false);
	fc = handle_fc(split, floor, ceiling);
	if (fc != -1)
		return (free_arr(split), fc);
	if (!handle_texture(map, split))
		return (free_arr(split), false);
	return (free_arr(split), true);
}
