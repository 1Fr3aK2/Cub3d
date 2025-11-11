/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamorim <raamorim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:39:30 by raamorim          #+#    #+#             */
/*   Updated: 2025/11/11 15:19:49 by raamorim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Cub3d.h>

bool	check_map(char *floor, char *ceiling, t_map *map)
{
	if (!floor || !ceiling || !map)
		return (false);
	if (!check_valid_chars(map))
		return (false);
	if (!check_player(map))
		return (false);
	if (!alloc_temp_map(map))
		return (false);
	if (!check_surroundings(map))
		return (false);
	if (!check_textures(floor, ceiling, map))
		return (false);
	return (true);
}

bool	check_valid_chars(t_map *map)
{
	int	i;
	int	j;
	int	k;

	if (!map || !map->map)
		return (false);
	i = 0;
	while (map->map[i] && i < map->height)
	{
		j = 0;
		while (map->map[i][j])
		{
			k = 0;
			while (VALID_CHARS[k] && map->map[i][j] != VALID_CHARS[k])
				k++;
			if (!VALID_CHARS[k])
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	check_player(t_map *map)
{
	int	i;
	int	j;
	int	player;

	if (!map || !check_valid_chars(map))
		return (false);
	player = 0;
	i = 0;
	while (map->map[i] && i < map->height)
	{
		j = 0;
		while (map->map[i][j])
		{
			if (is_player_char(map->map[i][j]))
			{
				player++;
				if (player > 1)
					return (false);
			}
			j++;
		}
		i++;
	}
	return (player == 1);
}

bool	alloc_temp_map(t_map *map)
{
	int	i;
	int	j;

	if (!map)
		return (false);
	i = 0;
	while (map->map[i])
		i++;
	map->temp_map = ft_calloc(sizeof(bool *), i + 1);
	if (!map->temp_map)
		return (false);
	i--;
	while (i >= 0)
	{
		j = 0;
		while (map->map[i][j])
			j++;
		map->temp_map[i] = malloc(j * sizeof(bool));
		if (!map->temp_map[i])
			return (false);
		i--;
	}
	set_bool(map);
	return (true);
}

void	set_bool(t_map *map)
{
	int		i;
	int		j;

	if (!map)
		return ;
	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			map->temp_map[i][j] = false;
			j++;
		}
		i++;
	}
}
