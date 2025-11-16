/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamorim <raamorim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 20:23:37 by rafael            #+#    #+#             */
/*   Updated: 2025/11/16 17:17:19 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Cub3d.h>

bool	is_wall(t_map *map, float y, float x)
{
	int	map_x;
	int	map_y;

	if (!map)
		return (false);
	map_y = (int)y;
	map_x = (int)x;
	if (map_y < 0 || map_x < 0 || !map->map[map_y] || !map->map[map_y][map_x])
		return (false);
	if (map->map[map_y][map_x] == WALL)
		return (true);
	return (false);
}

void	move_forward(t_data *data)
{
	float	new_x;
	float	new_y;

	if (!data)
		return ;
	new_x = data->player.x + data->player.dir_x * MOVE_SPEED;
	new_y = data->player.y + data->player.dir_y * MOVE_SPEED;
	if (!is_wall(&data->map, data->player.y, new_x))
		data->player.x = new_x;
	if (!is_wall(&data->map, new_y, data->player.x))
		data->player.y = new_y;
}

void	move_backward(t_data *data)
{
	float	new_x;
	float	new_y;

	if (!data)
		return ;
	new_x = data->player.x - data->player.dir_x * MOVE_SPEED;
	new_y = data->player.y - data->player.dir_y * MOVE_SPEED;
	if (!is_wall(&data->map, data->player.y, new_x))
		data->player.x = new_x;
	if (!is_wall(&data->map, new_y, data->player.x))
		data->player.y = new_y;
}

void	move_left(t_data *data)
{
	float	new_y;
	float	new_x;

	if (!data)
		return ;
	new_x = data->player.x + data->player.dir_x * MOVE_SPEED;
	new_y = data->player.y + data->player.dir_y * MOVE_SPEED;
	if (!is_wall(&data->map, data->player.y, new_x))
		data->player.x = new_x;
	if (!is_wall(&data->map, new_y, data->player.x))
		data->player.y = new_y;
}

void	move_right(t_data *data)
{
	float	new_y;
	float	new_x;

	if (!data)
		return ;
	new_x = data->player.x + data->player.dir_x * MOVE_SPEED;
	new_y = data->player.y + data->player.dir_y * MOVE_SPEED;
	if (!is_wall(&data->map, data->player.y, new_x))
		data->player.x = new_x;
	if (!is_wall(&data->map, new_y, data->player.x))
		data->player.y = new_y;
}
