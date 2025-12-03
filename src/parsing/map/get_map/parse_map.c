/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:54:45 by rafael            #+#    #+#             */
/*   Updated: 2025/12/03 00:35:52 by rafael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Cub3d.h>


bool parse_map(t_data *data, char **floor, char **ceiling)
{
    int i;
	char **split;
	
	split = NULL;
	i = 0;
    if (!data)
        return (exit_error(data, "ERROR:\nparse_map, invalid data pointer"), false);
    while (!check_load_textures(*floor, *ceiling, &data->map))
    {
        if (!data->map.buffer[i])
            exit_error(data, "ERROR:\nparse_map, reading texture!");
        if (data->map.buffer[i][0] == '\0')
        {
            i++;
            continue;
        }
        if (data->map.buffer[i][0] == 'F' && !*floor)
        {
            char **sp = ft_split(data->map.buffer[i], ' ');
            if (sp && sp[1])
                *floor = ft_strdup(sp[1]);
            free_arr(sp);
            i++;
            continue;
        }
        if (data->map.buffer[i][0] == 'C' && !*ceiling)
        {
            split = ft_split(data->map.buffer[i], ' ');
            if (split && split[1])
                *ceiling = ft_strdup(split[1]);
            free_arr(split);
            i++;
            continue;
        }
        if (!set_texture(replace_tabs(data->map.buffer[i]), &data->map))
            exit_error(data, "ERROR:\nparse_map, reading textures!");
        i++;
    }
    if (!set_map(&data->map, i))
        return (exit_error(data, "ERROR:\nparse_map, error setting map!"), false);
    data->map.height = ft_stralen(data->map.map);
    return (true);
}



bool	set_map(t_map *map, int i)
{
	int	len;
	int	mapp;
	int	temp;

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
	if (!alloc_map(map, &mapp))
		return (false);
	return (true);
}

bool	alloc_map(t_map *map, int *i)
{
	if (!map || !map->buffer || !i || *i < 0)
		return (false);
	map->map = &map->buffer[*i];
	if (!map->map)
		return (false);
	return (true);
}
