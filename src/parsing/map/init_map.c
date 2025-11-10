/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:11:03 by raamorim          #+#    #+#             */
/*   Updated: 2025/11/10 17:36:43 by rafael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Cub3d.h>

int	init_map(char *file, t_data *data)
{
	if (!file || !data)
		return (-1);
	check_map_name(file);
	get_lines(data, file);
	get_map(file, data);
	if (check_map(&data->map) == false)
		exit_error(data, "ERROR:\ncheck_map");
	if (set_fc_rgb(data) == false)
		exit_error(data, "ERROR:\nset_fc_rgb");
	init_player(data);	
	return (1);
}

bool set_fc_rgb(t_data *data)
{
	if (!data)
		return (false);
	data->map.rgb_ceiling = set_rgb(data->map.ceiling, data);
	if (!data->map.rgb_ceiling)
		return (false);
	if (data->map.ceiling)
	{
		free(data->map.ceiling);
		data->map.ceiling = NULL;
	}
	data->map.rgb_floor = set_rgb(data->map.floor, data);
	if (!data->map.rgb_floor)
		return (false);
	if (data->map.floor)
	{
		free(data->map.floor);
		data->map.floor = NULL;
	}
	return (true);
}
