/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamorim <raamorim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 20:23:37 by rafael            #+#    #+#             */
/*   Updated: 2025/11/17 13:14:25 by raamorim         ###   ########.fr       */
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
	float	new_x;
	float	new_y;

	new_x = data->player.x + data->player.dir_y * MOVE_SPEED;
	new_y = data->player.y - data->player.dir_x * MOVE_SPEED;
	if (!is_wall(&data->map, data->player.y, new_x))
		data->player.x = new_x;
	if (!is_wall(&data->map, new_y, data->player.x))
		data->player.y = new_y;
}
void	move_right(t_data *data)
{
	float	new_x;
	float	new_y;

	new_x = data->player.x - data->player.dir_y * MOVE_SPEED;
	new_y = data->player.y + data->player.dir_x * MOVE_SPEED;
	if (!is_wall(&data->map, data->player.y, new_x))
		data->player.x = new_x;
	if (!is_wall(&data->map, new_y, data->player.x))
		data->player.y = new_y;
}

void	movemnts(t_data *data)
{
	if (data->keys & FORWARD)
		move_forward(data);
	if (data->keys & BACKWARDS)
		move_backward(data);
	if (data->keys & LEFT_S)
		move_left(data);
	if (data->keys & RIGHT_S)
		move_right(data);
	if (data->keys & TURN_L)
		move_left(data);
	if (data->keys & TURN_R)
		move_right(data);
}

void	set_bit(uint8_t *var, int bit, bool value)
{
	if (value)
		*var |= (1 << bit);
	else
		*var &= ~(1 << bit);
}
