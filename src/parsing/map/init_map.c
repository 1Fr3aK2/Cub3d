/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamorim <raamorim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:11:03 by raamorim          #+#    #+#             */
/*   Updated: 2025/11/11 13:51:14 by raamorim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Cub3d.h>

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
	return (1);
}

bool	set_fc_rgb(char *floor, char *ceiling, t_data *data)
{
	if (!floor || !ceiling || !data)
		return (false);
	data->map.rgb_ceiling = set_rgb(ceiling, data);
	if (!data->map.rgb_ceiling)
		return (false);
	if (ceiling)
		free(ceiling);
	data->map.rgb_floor = set_rgb(floor, data);
	if (!data->map.rgb_floor)
		return (false);
	if (floor)
		free(floor);
	return (true);
}
