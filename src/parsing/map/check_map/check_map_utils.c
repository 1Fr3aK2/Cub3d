/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamorim <raamorim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:41:25 by raamorim          #+#    #+#             */
/*   Updated: 2025/11/11 13:39:07 by raamorim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Cub3d.h>

bool	is_valid(char *arr, char c)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (c == arr[i])
			return (true);
		i++;
	}
	return (false);
}

bool	flood_fill_map(t_map *map, int i, int j)
{
	if (!map || i < 0 || j < 0 || !map->map[i]
		|| j >= (int)ft_strlen(map->map[i]) || map->map[i][j] == ' ')
		return (false);
	if (map->map[i][j] == '1' || map->temp_map[i][j])
		return (true);
	map->temp_map[i][j] = true;
	if (!flood_fill_map(map, i + 1, j))
		return (false);
	if (!flood_fill_map(map, i - 1, j))
		return (false);
	if (!flood_fill_map(map, i, j + 1))
		return (false);
	if (!flood_fill_map(map, i, j - 1))
		return (false);
	return (true);
}

bool	check_surroundings(t_map *map)
{
	int	i;
	int	j;

	if (!map)
		return (false);
	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if ((map->map[i][j] == '0' || is_valid(PLAYER, map->map[i][j]))
				&& map->temp_map[i][j] == false)
			{
				if (!flood_fill_map(map, i, j))
					return (ft_putendl_fd("check_surroundings", 2), false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

bool	verify_texture(char *path)
{
	int	fd;

	if (!path)
		return (false);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (false);
	close(fd);
	return (true);
}
