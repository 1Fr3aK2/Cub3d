/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:11:03 by raamorim          #+#    #+#             */
/*   Updated: 2025/12/11 02:43:30 by rafael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Cub3d.h>

static inline size_t	get_max_w(char **map)
{
	size_t	len;
	size_t	max;
	size_t	i;

	i = 0;
	max = ft_strlen(map[i++]);
	len = max;
	while (map[i])
	{
		len = ft_strlen(map[i++]);
		if (len > max)
			max = len;
	}
	return (max);
}

int	init_map(char *file, t_data *data)
{
	char	*floor;
	char	*ceiling;

	if (!file || !data)
		return (-1);
	floor = NULL;
	ceiling = NULL;
	check_map_name(file);
	get_lines(data, file);
	get_map(file, &floor, &ceiling, data);
	if (!check_map(floor, ceiling, &data->map))
		exit_error(data, "ERROR:\ncheck_map");
	if (!set_fc_rgb(floor, ceiling, data))
		exit_error(data, "ERROR:\nset_fc_rgb");
	init_player(data);
	data->map.max_w = get_max_w(data->map.map);
	data->map.max_h = ft_stralen(data->map.map);
	return (1);
}

bool	set_fc_rgb(char *floor, char *ceiling, t_data *data)
{
	if (!floor || !ceiling || !data)
		return (false);
	data->map.rgb_ceiling = set_rgb(ceiling, data);
	if (ceiling)
		free(ceiling);
	if (!data->map.rgb_ceiling)
		return (false);
	data->map.rgb_floor = set_rgb(floor, data);
	if (floor)
		free(floor);
	if (!data->map.rgb_floor)
		return (false);
	return (true);
}
