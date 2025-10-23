/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:54:45 by rafael            #+#    #+#             */
/*   Updated: 2025/10/23 22:42:54 by rafael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Cub3d.h>

bool	parse_map(t_data *data)
{
	int	i;

	i = 0;
	if (!data)
		return (exit_error(data, "ERROR:\n parse_map, invalid data pointer\n"), false);
	while (!check_load_textures(&data->map))
	{
		if (!data->map.buffer[i])
			exit_error(data, "ERROR:\n parse_map,reading texture!");
		if (data->map.buffer[i][0] == '\0')
		{
			i++;
			continue ;
		}
		if (!set_texture(replace_tabs(data->map.buffer[i]), &data->map))
			exit_error(data, "ERROR:\n parse_map,reading textures!");
		i++;
	}
	if (set_map(&data->map, i) == false)
		return (exit_error(data, "ERROR:\n parse_map, error setting map!"), false);
	data->map.height = ft_stralen(data->map.map);
	return (true);
}

bool	set_map(t_map *map, int i)
{
	int	len;
	int	mapp;
	int temp;

	if (!map || i < 0)
		return (false);
	len = 0;
	temp = 0;
	while (map->buffer[i + temp] && map->buffer[i + temp][0] == '\0')
		temp++;
	if (!map->buffer[i + len + temp])
		return (false);
	while (map->buffer[i + len + temp])
		len++;
	mapp = (i + temp);
	if (alloc_map(map, &mapp) == false)
		return (false);
	return (true);
}

bool	alloc_map(t_map *map, int *i)
{
	int	index;

	index = 0;
	if (!map || !map->buffer || !i || *i < 0)
		return (false);
	map->map = ft_calloc(ft_stralen(map->buffer) - *i + 1, sizeof(char *));
	if (!map->map)
		return (false);
	while (map->buffer[*i])
	{
		map->map[index] = ft_strdup(map->buffer[*i]);
		if (!map->map[index])
		{
			ft_putendl_fd("Error setting the map", 2);
			free_arr(map->map, index);
			map->map = NULL;
			return (false);
		}
		(*i)++;
		index++;
	}
	free_arr(map->buffer, ft_stralen(map->buffer));
	map->buffer = NULL;
	return (true);
}
