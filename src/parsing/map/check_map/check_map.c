/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamorim <raamorim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:39:30 by raamorim          #+#    #+#             */
/*   Updated: 2025/10/24 18:44:56 by raamorim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Cub3d.h>

bool	check_map(t_map *map)
{
	if (!map)
		return (false);
	if (check_valid_chars(map) == false)
		return (false);
	if (check_player(map) == false)
		return (false);
	return (true);
}

bool	check_valid_chars(t_map *map)
{
	int	i;
	int	j;
	int	k;
	int	player;

	if (!map || !map->map)
		return (false);
	player = 0;
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
    int i;
	int player;
	int j;
	int k;
    
	if (!map)
		return (false);
	i = 0;
	j = 0;
	player = 0;
	if (check_valid_chars(map) == false)
		return (false);
	while (map->map[i] && i < map->height)
	{
		j = 0;
		while (map->map[i][j])
		{
			k = 0;
			while (PLAYER[k] && map->map[i][j] != PLAYER[k])
				k++;
			if (PLAYER[k] == map->map[i][j])
			{
				player++;
				if (player > 1)
					return (false);
			}
			j++;
		}
		i++;
	}
	if (player <= 0)
		return (false);
	return (true);
}