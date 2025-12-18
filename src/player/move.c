/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamorim <raamorim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 20:23:37 by rafael            #+#    #+#             */
/*   Updated: 2025/12/18 00:40:54 by htrindad         ###   ########.fr       */
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

void	move_forward(t_data *data, bool sides)
{
	float	new_x;
	float	new_y;
	float	speed;

	speed = MOVE_SPEED;
	if (sides)
		speed /= 2;
	if (!data)
		return ;
	new_x = data->player.x + data->player.dir_x * speed;
	new_y = data->player.y + data->player.dir_y * speed;
	if (!is_wall(&data->map, data->player.y, new_x))
		data->player.x = new_x;
	if (!is_wall(&data->map, new_y, data->player.x))
		data->player.y = new_y;
}

void	move_backward(t_data *data, bool sides)
{
	float	new_x;
	float	new_y;
	float	speed;

	speed = MOVE_SPEED;
	if (sides)
		speed /= 2;
	if (!data)
		return ;
	new_x = data->player.x - data->player.dir_x * speed;
	new_y = data->player.y - data->player.dir_y * speed;
	if (!is_wall(&data->map, data->player.y, new_x))
		data->player.x = new_x;
	if (!is_wall(&data->map, new_y, data->player.x))
		data->player.y = new_y;
}

void	move_left(t_data *data, bool sides)
{
	float	new_x;
	float	new_y;
	float	speed;

	speed = MOVE_SPEED;
	if (sides)
		speed /= 2;
	if (!data)
		return ;
	new_x = data->player.x + data->player.dir_y * speed;
	new_y = data->player.y - data->player.dir_x * speed;
	if (!is_wall(&data->map, data->player.y, new_x))
		data->player.x = new_x;
	if (!is_wall(&data->map, new_y, data->player.x))
		data->player.y = new_y;
}

void	move_right(t_data *data, bool sides)
{
	float	new_x;
	float	new_y;
	float	speed;

	speed = MOVE_SPEED;
	if (sides)
		speed /= 2;
	if (!data)
		return ;
	new_x = data->player.x - data->player.dir_y * speed;
	new_y = data->player.y + data->player.dir_x * speed;
	if (!is_wall(&data->map, data->player.y, new_x))
		data->player.x = new_x;
	if (!is_wall(&data->map, new_y, data->player.x))
		data->player.y = new_y;
}
