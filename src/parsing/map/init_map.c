/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:11:03 by raamorim          #+#    #+#             */
/*   Updated: 2025/11/04 00:07:46 by rafael           ###   ########.fr       */
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
		exit_error(data, "ERROR:\ncheck_map\n");
	init_player(data);	
	free_all(data);
	return (1);
}
